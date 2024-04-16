#ifndef REQUEST_QUEUE_H
#define REQUEST_QUEUE_H

#include <queue>

struct DiskRequest {
    int size;
    DiskRequest(int sz) : size(sz) {}
};

class RequestQueue {
private:
    std::queue<DiskRequest> requests;

public:
    void enqueue(const DiskRequest& request);
    DiskRequest dequeue();
    bool isEmpty() const;
};

#endif // REQUEST_QUEUE_H
