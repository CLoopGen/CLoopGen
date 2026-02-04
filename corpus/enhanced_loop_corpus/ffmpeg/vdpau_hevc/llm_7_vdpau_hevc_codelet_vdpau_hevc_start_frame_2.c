#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int64_t arr[16];
    for (size_t i = 0; i < 16; i++) {
        arr[i] = i;
        if (i > 0) {
            arr[i] += arr[i - 1]; // Introduce loop-carried read-after-write (RAW) dependency
        }
    }
    // Final value depends on full chain of prior writes
    volatile int64_t sink = arr[15];
}
