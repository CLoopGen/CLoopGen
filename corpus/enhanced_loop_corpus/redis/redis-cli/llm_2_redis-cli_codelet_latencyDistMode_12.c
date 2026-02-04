#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
struct distsamples {
    long long max;
    long long count;
    int character;
};


extern long long latency;
extern int j;
extern struct distsamples samples[];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size of 2
    for (j = 0; j < 1000; j += 2) {  // Assuming a safe upper bound to prevent out-of-bounds
        int next_idx = j + 1;
        if (next_idx < 1000 && (samples[next_idx].max == 0 || latency <= samples[next_idx].max)) {
            samples[next_idx].count++;
            break;
        }
        // Fallback to current index if next is invalid
        if (samples[j].max == 0 || latency <= samples[j].max) {
            samples[j].count++;
            break;
        }
    }
}
