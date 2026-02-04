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
    // Variant 2: Indirect memory access using a predefined index mapping (permuted order)
    int index_map[4] = {3, 1, 0, 2};  // Custom indirect access pattern
    for (i = 0; i < 4; i++) {
        int mapped_idx = index_map[i];
        if (temp >= nthreads) {
            temp = 0;
        }
        th_count[mapped_idx] = temp;
        temp = temp + 1;
    }
}
