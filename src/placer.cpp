#include "placer.h"
#include <iostream>

Placer::Placer(RequestQueue& q, Monitor& m, std::vector<Warehouse>& w)
    : queue(q), monitor(m), warehouses(w) {}

void Placer::processNextRequest() {
    if (!queue.isEmpty()) {
        DiskRequest request = queue.dequeue();
        int warehouseIndex = monitor.findLeastUtilizedWarehouseIndex(warehouses);
        if (warehouseIndex >= 0 && warehouseIndex < warehouses.size()) {
            if (warehouses[warehouseIndex].addDisk(request.size)) {
                std::cout << "A " << request.size << " TB disk mapped into warehouse" << warehouseIndex + 1 << std::endl;
            } else {
                std::cout << "Failed to place a " << request.size << " TB disk into warehouse" << warehouseIndex + 1 << " (not enough space)" << std::endl;
            }
        }
    }
}
