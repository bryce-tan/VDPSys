#include "request_queue.h"
#include "placer.h"
#include "monitor.h"
#include "warehouse.h"
#include <thread>
#include <chrono>
#include <iostream>
#include <random>
#include <string>
#include <thread>
#include <iomanip>
void clearScreen(){
    std::cout << "\033[2J\033[H";
}

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
        Warehouse(10000), // Initialize warehouses with capacities
        
        Warehouse(20000),
        Warehouse(20000),
        Warehouse(30000),
        Warehouse(40000),
        Warehouse(40000),
    };
    Monitor monitor(warehouses.size());
    Placer placer(queue, monitor, warehouses);

    // Random
    std::random_device rd;
    std::default_random_engine generator(rd());

    // Threads
    std::atomic<int> totalDisksPlaced(0); // Tracing the VDs
     // Treads for status outputs
    std::thread statusThread([&]() {
        while (!monitor.allWarehousesFull()) {
            std::this_thread::sleep_for(std::chrono::microseconds(100)); // Update every 1s
            // clearScreen();
            std::cout << "Total disks placed: " << totalDisksPlaced << std::endl;
            for (size_t i = 0; i < warehouses.size(); ++i) {
                float utilization = warehouses[i].utilization();
                std::cout << "Warehouse " << i + 1 << " utilization: " 
                          << std::fixed << std::setprecision(2) << utilization * 100.0f << "% ";
                int progressBarWidth = 50; // Width of bars
                int pos = progressBarWidth * utilization;
                std::cout << "[";
                for (int j = 0; j < progressBarWidth; ++j) {
                    if (j < pos) std::cout << "=";
                    else if (j == pos) std::cout << ">";
                    else std::cout << " ";
                }
                std::cout << "]\n";
            }
            std::cout << std::endl;
        }
    });


    // Main loop to process requests
    while (!monitor.allWarehousesFull()) {
        // VD arrival simulation
        int diskSize = std::uniform_int_distribution<int>(1,20)(generator);
        queue.enqueue(DiskRequest(diskSize));
        monitor.updateAvailability(warehouses);
        // Processing VD placement
        if(!queue.isEmpty()){
            if (placer.processNextRequest()){
                totalDisksPlaced++;
            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(5));
    }

    statusThread.join();

    std::cout << "All warehouses are full. Simulation terminated." << std::endl;
    return 0; // This line will actually never be reached due to the infinite loop
}
