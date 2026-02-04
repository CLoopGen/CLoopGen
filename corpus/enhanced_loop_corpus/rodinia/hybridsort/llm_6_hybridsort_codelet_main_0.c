#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *sizes;
extern int newlistsize;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_sum = 0;
    for (int i = 0; i < (1 << 10); i++) {
        temp_sum += sizes[i] * 4;
    }
    newlistsize += temp_sum;
}
