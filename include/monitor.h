#ifndef MONITOR_H
#define MONITOR_H

#include "warehouse.h"
#include <vector>

class Monitor {
public:
    int findLeastUtilizedWarehouseIndex(const std::vector<Warehouse>& warehouses);
};

#endif // MONITOR_H
