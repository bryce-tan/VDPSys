#ifndef PLACER_H
#define PLACER_H

#include "request_queue.h"
#include "monitor.h"
#include "warehouse.h"
#include <vector>

class Placer {
private:
    RequestQueue& queue;
    Monitor& monitor;
    std::vector<Warehouse>& warehouses;

public:
    Placer(RequestQueue& q, Monitor& m, std::vector<Warehouse>& w);
    void processNextRequest();
};

#endif // PLACER_H
