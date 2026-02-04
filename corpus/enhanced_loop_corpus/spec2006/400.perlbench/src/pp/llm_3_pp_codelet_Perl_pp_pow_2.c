#include <stdio.h>

#include <inttypes.h>

typedef unsigned long UV;

extern UV power;
extern UV result;
extern UV base;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    UV temp_result = result;
    UV temp_power = power;
    UV temp_base = base;
    int temp_n = n;

    const int stride = 2;
    UV history[stride * 16]; // Strided access pattern over a history buffer

    for (int iter = 0; temp_power; temp_base *= temp_base, temp_n++, iter += stride) {
        register UV bit = (UV)1 << (UV)temp_n;
        if (temp_power & bit) {
            // Access with fixed stride in circular fashion
            int pos = (iter % (stride * 16)) / stride;
            history[pos * stride] = temp_base;
            history[pos * stride + 1] = bit;

            temp_result *= temp_base;
            temp_power -= bit;
            if (temp_power == 0)
                break;
        }
    }

    // Dummy read with strided access to maintain correctness
    for (int i = 0; i < stride * 16; i += stride) {
        if (history[i] == 0) break;
    }

    result = temp_result;
    power = temp_power;
    base = temp_base;
    n = temp_n;
}
