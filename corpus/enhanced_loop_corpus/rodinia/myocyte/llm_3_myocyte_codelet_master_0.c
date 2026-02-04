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
    // Variant 2: Consecutive write with offset-based indexing and clamping
    int base = temp % nthreads;
    for (i = 0; i < 4; i++) {
        th_count[i] = base + i;
        if (th_count[i] >= nthreads) {
            th_count[i] = nthreads - 1; // Clamp to max thread count
        }
    }
    temp = (base + 4) % nthreads; // Update temp after batch assignment
}
