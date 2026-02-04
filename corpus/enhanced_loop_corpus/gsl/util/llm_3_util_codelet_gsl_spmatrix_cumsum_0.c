#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t n;
extern int *c;
extern int sum;
extern size_t k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access
    // Traverse the array from the last element to the first
    for (k = n; k > 0; --k) {
        size_t index = k - 1;
        int ck = c[index];
        c[index] = sum;
        sum += ck;
    }
}
