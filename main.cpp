#include "request_queue.h"
#include "placer.h"
#include "monitor.h"
#include "warehouse.h"
#include <thread>
#include <chrono>
#include <iostream>
#include <random>
#include <string>

int main() {

    std::string command;
    std::cout << "Enter 'startsim' to start the simulation." << std::endl;

    // Waiting for command
    while (true) {
        std::cin >> command;
        if (command == "startsim") {
            break;
        }
        std::cout << "Invalid command. Please enter 'startsim' to start the simulation." << std::endl;
    }

    //Initialize
    RequestQueue queue;
    std::vector<Warehouse> warehouses = {
        Warehouse(100), // Initialize warehouses with capacities
        Warehouse(200)
    };
    Monitor monitor(warehouses.size());
    Placer placer(queue, monitor, warehouses);

    // Setup a random number generator for Poisson-distributed arrival times
    std::default_random_engine generator(std::random_device{}());
    std::poisson_distribution<int> distribution(2); // Example mean arrival rate

    // Main loop to process requests
    while (!monitor.allWarehousesFull()) {
        // Check for the arrival of a new disk request
        if (distribution(generator) > 0) {
            int diskSize = std::uniform_int_distribution<int>(1, 50)(generator); // Random disk size between 1 and 50
            queue.enqueue(DiskRequest(diskSize));
            std::cout << "A " << diskSize << " TB disk arrives." << std::endl;
        }
        monitor.updateAvailability(warehouses);
        // Process any pending requests
        placer.processNextRequest();

        // Simulate time passing
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
    std::cout << "All warehouses are full. Simulation terminated." << std::endl;
    return 0; // This line will actually never be reached due to the infinite loop
}
