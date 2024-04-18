#include "monitor.h"
#include <cstddef> // 

// 
Monitor::Monitor(size_t warehouseCount) : warehouseAvailability(warehouseCount, true) {}

// 
void Monitor::updateAvailability(std::vector<Warehouse>& warehouses) {
    for (size_t i = 0; i < warehouses.size(); ++i) {
        if (warehouses[i].isFull()) {
            warehouseAvailability[i] = false;
        }
    }
}

int Monitor::findLeastUtilizedWarehouseIndex(const std::vector<Warehouse>& warehouses) {
    int index = -1;
    float leastUtilization = 1.0f; // Start with 100% utilization

    for (std::size_t i = 0; i < warehouses.size(); ++i) {
        if (!warehouseAvailability[i]) continue; // 
        float utilization = warehouses[i].utilization();
        if (utilization < leastUtilization) {
            leastUtilization = utilization;
            index = i;
        }
    }

    return index;
}

bool Monitor::allWarehousesFull() const{
    for (bool available : warehouseAvailability){
        if (available) return false;
    }
    return true;
}