#include "request_queue.h"
#include "placer.h"
#include "monitor.h"
#include "warehouse.h"

int main() {
    RequestQueue queue;
    Monitor monitor;
    std::vector<Warehouse> warehouses = {
        Warehouse(100), // Initialize warehouses with capacities
        Warehouse(200)
    };
    
    Placer placer(queue, monitor, warehouses);

    // Simulate incoming requests
    queue.enqueue(DiskRequest(10)); // Request for a disk of size 10
    queue.enqueue(DiskRequest(20)); // Request for a disk of size 20

    // Main loop to process requests
    while (!queue.isEmpty()) {
        placer.processNextRequest();
    }

    return 0;
}
