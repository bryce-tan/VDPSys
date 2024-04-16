#ifndef WAREHOUSE_H
#define WAREHOUSE_H

class Warehouse {
private:
    int capacity;
    int used;

public:
    Warehouse(int cap);
    bool addDisk(int size);
    float utilization() const; // Returns the current utilization percentage
};

#endif // WAREHOUSE_H
