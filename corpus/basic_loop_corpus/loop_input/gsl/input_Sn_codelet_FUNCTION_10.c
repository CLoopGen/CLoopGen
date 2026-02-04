#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <stdint.h>

double medA = 0.0;
double medB = 0.0;
int i = 0;
int diff = 0;
int half = 0;
int Amin = 0;
int Amax = 0;
int even = 0;
int length = 0;
int leftA = 0;
int leftB = 0;
int nA = 0;
int nB = 10000;
int tryA = 0;
int tryB = 0;
int rightA = 0;
int rightB = 0;
int np1_2 = 5000;

void init_vars() {
    const int target_time_ns = 10000000; // 10 ms in nanoseconds
    struct timespec start, end;

    // Warm-up run to estimate execution time
    clock_gettime(CLOCK_MONOTONIC, &start);
    for (i = 2; i <= np1_2; ++i) {
        nA = i - 1;
        diff = nB - nA;
        leftA = leftB = 1;
        rightA = rightB = nB;
        Amin = diff / 2 + 1;
        Amax = diff / 2 + nA;
        while (leftA < rightA) {
            length = rightA - leftA + 1;
            even = 1 - length % 2;
            half = (length - 1) / 2;
            tryA = leftA + half;
            tryB = leftB + half;
            if (tryA < Amin) {
                rightB = tryB;
                leftA = tryA + even;
            } else {
                if (tryA > Amax) {
                    rightA = tryA;
                    leftB = tryB + even;
                } else {
                    if (medA >= medB) {
                        rightA = tryA;
                        leftB = tryB + even;
                    } else {
                        rightB = tryB;
                        leftA = tryA + even;
                    }
                }
            }
        }
    }

    clock_gettime(CLOCK_MONOTONIC, &end);
    long elapsed_ns = (end.tv_sec - start.tv_sec) * 1000000000L + (end.tv_nsec - start.tv_nsec);

    if (elapsed_ns == 0) {
        np1_2 = 5000; // default safe value
    } else {
        double ratio = (double)target_time_ns / elapsed_ns;
        np1_2 = (int)(np1_2 * ratio);
        if (np1_2 < 2) np1_2 = 2;
        if (np1_2 > 1000000) np1_2 = 1000000;
    }

    // Initialize nB to a reasonable size
    nB = 10000;

    // Initialize medians
    medA = 50.0;
    medB = 50.0;
}