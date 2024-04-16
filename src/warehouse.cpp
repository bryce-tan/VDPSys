#include "warehouse.h"

Warehouse::Warehouse(int cap) : capacity(cap), used(0) {}

bool Warehouse::addDisk(int size) {
    if (used + size <= capacity) {
        used += size;
        return true;
    } else {
        return false;
    }
}

float Warehouse::utilization() const {
    return static_cast<float>(used) / capacity;
}
