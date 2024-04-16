#include "request_queue.h"

void RequestQueue::enqueue(const DiskRequest& request) {
    requests.push(request);
}

DiskRequest RequestQueue::dequeue() {
    if (isEmpty()) {
        throw std::out_of_range("Request queue is empty.");
    }
    DiskRequest request = requests.front();
    requests.pop();
    return request;
}

bool RequestQueue::isEmpty() const {
    return requests.empty();
}
