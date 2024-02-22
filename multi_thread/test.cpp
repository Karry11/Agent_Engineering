#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include "SafeQueue.h"
#include <memory>
#include "typeinfo"
template<typename T>
void logger(const T& value){
    std::cout<< value << std::endl;
}

void simulate_hard_computation()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
}

// 添加两个数字的简单函数并打印结果
void multiply(const int a, const int b)
{
    simulate_hard_computation();
    const int res = a * b;
    std::cout << a << " * " << b << " = " << res << std::endl;
}
void multiply_output(int &out, const int a, const int b)
{
    simulate_hard_computation();
    out = a * b;
    std::cout << a << " * " << b << " = " << out << std::endl;
}

int main() {
    ThreadPool pool(10);
    pool.init();
    for (int i = 1; i <= 3; ++i)
        for (int j = 1; j <= 10; ++j) {
            pool.submit(multiply, i, j);
        }
    int output_ref;
    auto future1 = pool.submit(multiply_output, std::ref(output_ref), 5, 6);
    future1.get();
    std::cout << "Last operation result is equals to " << output_ref << std::endl;
    pool.shutdown();
    return 0;
}
