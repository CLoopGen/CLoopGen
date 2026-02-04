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
extern int new_size;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2, unrolling by 2 iterations
    // Ensures we don't exceed bounds by checking i+1
    int n = new_size;
    int limit = n - (n % 2); // Make it even to avoid out-of-bounds in pairs
    for (i = 0; i < limit; i += 2) {
        px->pe[i]     = i;
        px->pe[i + 1] = i + 1;
    }
    // Handle leftover element if new_size is odd
    if (limit < new_size)
        px->pe[limit] = limit;
}
