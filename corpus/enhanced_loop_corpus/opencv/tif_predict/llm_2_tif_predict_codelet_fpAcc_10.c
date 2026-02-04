#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int tmsize_t;

extern tmsize_t count;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    tmsize_t i;
    for (i = count; i > 1; i -= 2) {
        // Strided memory access pattern: simulate access with stride of 2
        // Assuming we had an array, we'd access elements like arr[i], arr[i-2], etc.
        __asm__ volatile("" : "+r"(i) : : "memory"); // Simulated strided memory touch
    }
}
