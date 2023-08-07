#include <iostream>
#include "timer.h"

Timer::Timer() {
    start_time = std::chrono::high_resolution_clock::now();
}

Timer::~Timer() {
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end_time - start_time;
    float ms = duration.count() * 1000;
    std::cout << "Elapsed time: " << ms << " ms" << std::endl;
}

/*
// Example usage
void myFunction() {
    Timer timer; // Start the timer
    // Perform the operations you want to time here

    // Simulating some work
    for (int i = 0; i < 10000; ++i) {
        std::cout << "Hello\n";
    }
}

int main() {
    myFunction();
    return 0;
}
*/
