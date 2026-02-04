#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int nthreads;
extern int th_count[4];
extern int temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int prev_index = -1;
    for (i = 0; i < 4; i++) {
        if (temp >= nthreads) {
            temp = 0;
        }
        th_count[i] = temp;
        if (prev_index != -1) {
            th_count[i] += th_count[prev_index]; // Introduce RAW dependency: current use of previous value
        }
        temp = temp + 1;
        prev_index = i;
    }
}
