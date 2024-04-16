#include "monitor.h"
#include <cstddef>

int Monitor::findLeastUtilizedWarehouseIndex(const std::vector<Warehouse>& warehouses) {
    int index = -1;
    float leastUtilization = 1.0f; // Start with 100% utilization

    for (size_t i = 0; i < warehouses.size(); ++i) {
        float utilization = warehouses[i].utilization();
        if (utilization < leastUtilization) {
            leastUtilization = utilization;
            index = i;
        }
    }

    return index;
}
