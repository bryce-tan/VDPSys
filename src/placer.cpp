#include "placer.h"
#include <iostream>

Placer::Placer(RequestQueue& q, Monitor& m, std::vector<Warehouse>& w)
    : queue(q), monitor(m), warehouses(w) {}

bool Placer::processNextRequest() {
    if (!queue.isEmpty()) {
        DiskRequest request = queue.dequeue();
        int warehouseIndex = monitor.findLeastUtilizedWarehouseIndex(warehouses);
        if (warehouseIndex >= 0 && warehouseIndex < warehouses.size()) {
            return warehouses[warehouseIndex].addDisk(request.size);
        }
    }
    return false;
}
