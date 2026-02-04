#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char dc_in_use[16];
extern char ac_in_use[16];
extern int length;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2, processing even indices first then odd
    int temp_length = 0;
    for (i = 0; i < 16; i += 2)
        temp_length += dc_in_use[i] + ac_in_use[i];
    for (i = 1; i < 16; i += 2)
        temp_length += dc_in_use[i] + ac_in_use[i];
    length += temp_length;
}
