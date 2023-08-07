
#include <chrono>

class Timer{
public:
    Timer();
    ~Timer();

private:
    std::chrono::high_resolution_clock::time_point start_time;
};
