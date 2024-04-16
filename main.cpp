#include "request_queue.h"
#include "placer.h"
#include "monitor.h"
#include "warehouse.h"
#include <thread> // 新增头文件，用于暂停操作
#include <chrono> // 新增头文件，用于处理时间
#include <iostream>

int main() {
    RequestQueue queue;
    Monitor monitor;
    std::vector<Warehouse> warehouses = {
        Warehouse(100), // 初始化仓库容量
        Warehouse(200)
    };
    
    Placer placer(queue, monitor, warehouses);

    // 系统运行标志
    bool systemRunning = true;

    // 主循环，模拟持续运行的系统
    while (systemRunning) {
        // 模拟随机请求到来
        if (rand() % 10 < 2) { // 假设有20%的机率在任一时刻生成新请求
            int randomSize = rand() % 50 + 1; // 随机生成1到50之间的云盘大小
            std::cout << "Enqueuing new disk request of size " << randomSize << std::endl;
            queue.enqueue(DiskRequest(randomSize));
        }

        // 处理队列中的请求
        while (!queue.isEmpty()) {
            placer.processNextRequest();
        }

        // 暂停一段时间，例如1秒，来模拟请求到来的时间间隔
        std::this_thread::sleep_for(std::chrono::seconds(1));
        
        // 可以设置某些条件来停止系统运行
        // systemRunning = false; 
    }

    return 0;
}
