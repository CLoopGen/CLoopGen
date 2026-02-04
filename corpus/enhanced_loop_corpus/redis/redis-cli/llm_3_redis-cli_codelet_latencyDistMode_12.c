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
    // Variant 2: Consecutive access using pointer arithmetic for improved locality
    struct distsamples* base = samples;
    for (j = 0; j < 1000; j++) {  // Bounded loop to ensure safety
        struct distsamples* current = base + j;
        if (current->max == 0 || latency <= current->max) {
            current->count++;
            break;
        }
    }
}
