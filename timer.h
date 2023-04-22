//
// Created by Linqi Xiao on 4/22/2023.
//

#ifndef SORTED_TIMER_H
#define SORTED_TIMER_H

#include <ctime>

class Timer {
private:
    clock_t c1;
    clock_t c2;

public:
    Timer() {
        c1 = clock();
        c2 = clock();
    }

    void start() {
        c1 = clock();
    }

    void stop() {
        c2 = clock();
    }

    time_t total() {
        double diffms = (c2 - c1) / (CLOCKS_PER_SEC / 1000);
        return diffms;
    }
};

#endif //SORTED_TIMER_H
