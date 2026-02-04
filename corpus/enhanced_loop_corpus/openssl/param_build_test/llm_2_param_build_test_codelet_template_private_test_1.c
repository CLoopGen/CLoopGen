#include <stdio.h>

#include <inttypes.h>

extern int *data2;
extern int j;
extern  int data2_num;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element in increasing stride)
    for (j = 0; j < data2_num; j += 2)
        data2[j] = 2 * j;
}
