#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    u_int size;
    u_int max_size;
    u_int *pe;
} PERM;

extern PERM *px;
extern u_int i;
extern u_int j;
extern u_int entry;
extern u_int ok;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2) with bounds check
    for (j = 0; j < i; j += 2)
        ok &= (entry != px->pe[j]);
    // Handle odd-sized ranges by checking the last element if i is odd
    if (i > 0 && (i % 2) == 1)
        ok &= (entry != px->pe[i - 1]);
}
