#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int end_x;
extern int n;
extern uint8_t *a;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by unrolling the loop to access two elements per iteration
    // This changes the original strided-2 access into more sequential pattern with unrolling
    int i;
    for (i = 1; i < end_x - 1; i += 2) {
        a[i] = a[i - 1];
        if (i + 2 < end_x) {
            a[i + 2] = a[i + 1];
        }
    }
    // Handle case when end_x is the last odd index
    if (end_x > 0 && (end_x - 1) % 2 == 0 && (end_x - 1) >= 1) {
        a[end_x - 1] = a[end_x - 2];
    }
}
