#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t *histogram;
extern uint32_t total_windows;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2)
    for (i = 0; i < 12000; i += 2) {
        total_windows += histogram[i];
        if (i + 1 < 12000) {
            total_windows += histogram[i + 1];
        }
    }
}
