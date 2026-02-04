#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int bits;
extern int shift;
extern int coeff_mask;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Memory Access Pattern Modification using indirect access via pointer array
    // Use an array of pointers to simulate indirect memory access
    volatile int mask_copy = coeff_mask;
    volatile int *ptr_arr[8];
    for (int i = 0; i < 8; ++i) {
        ptr_arr[i] = (volatile int*)((char*)&mask_copy + (i & 1 ? 0 : sizeof(int)));
    }
    for (shift = 0; shift < 7 && bits + shift < 16; shift++) {
        volatile int data = *(ptr_arr[shift]);
        if (!(data & (1 << shift))) {
            continue;
        } else {
            break;
        }
    }
}
