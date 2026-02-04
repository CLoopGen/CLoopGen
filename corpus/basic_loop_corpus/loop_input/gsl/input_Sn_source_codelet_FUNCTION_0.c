#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>

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
int nB = 100000;
int tryA = 0;
int tryB = 0;
int rightA = 0;
int rightB = 0;
int np1_2 = 50000;

void init_vars() {
    const int target_time_ns = 10000000; // ~10ms in nanoseconds
    struct timespec start, end;
    
    // Warm-up run to estimate execution time scaling
    clock_gettime(CLOCK_MONOTONIC, &start);
    for (i = 2; i <= 1000; ++i) {
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
    
    // Scale np1_2 to achieve approximately 10ms runtime
    if (elapsed_ns > 0) {
        double ratio = (double)target_time_ns / elapsed_ns;
        np1_2 = (int)(1000 * ratio);
        if (np1_2 < 2) np1_2 = 2;
        if (np1_2 > 1000000) np1_2 = 1000000;
    } else {
        np1_2 = 50000;
    }

    // Ensure nB is large enough to avoid index issues
    nB = np1_2 + 1000;
    if (nB < 10000) nB = 10000;

    // Initialize medians to ensure balanced branching
    medA = 1.0;
    medB = 1.0;
}