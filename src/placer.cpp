#include "placer.h"

Placer::Placer(RequestQueue& q, Monitor& m, std::vector<Warehouse>& w)
    : queue(q), monitor(m), warehouses(w) {}

void Placer::processNextRequest() {
    if (!queue.isEmpty()) {
        DiskRequest request = queue.dequeue();
        int warehouseIndex = monitor.findLeastUtilizedWarehouseIndex(warehouses);
        if (warehouseIndex >= 0 && warehouseIndex < warehouses.size()) {
            if (warehouses[warehouseIndex].addDisk(request.size)) {
                // Log success
            } else {
                // Log failure or retry
            }
        }
    }
}
