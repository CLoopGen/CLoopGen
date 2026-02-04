#include <stdio.h>

#include <inttypes.h>

extern int *table;
extern int sum_of_weights;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2, accessing even indices only)
    for (i = 0; i < 8; i += 2)
        sum_of_weights += table[i];
}
