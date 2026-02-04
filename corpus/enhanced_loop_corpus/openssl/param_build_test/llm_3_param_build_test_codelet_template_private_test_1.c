#include <stdio.h>

#include <inttypes.h>

extern int *data2;
extern int j;
extern  int data2_num;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access (iterate from end to beginning)
    for (j = data2_num - 1; j >= 0; j--)
        data2[j] = 2 * j;
}
