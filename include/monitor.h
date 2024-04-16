#ifndef MONITOR_H
#define MONITOR_H

#include "warehouse.h"
#include <vector>

class Monitor {
private:
    std::vector<bool> warehouseAvailability; // 

public:
    Monitor(size_t warehouseCount); // 
    void updateAvailability(std::vector<Warehouse>& warehouses); // 
    int findLeastUtilizedWarehouseIndex(const std::vector<Warehouse>& warehouses);
    bool allWarehousesFull() const;
};

#endif // MONITOR_H
