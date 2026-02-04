#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t *histogram;
extern uint32_t total_windows;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t local_sum = 0;
    for (i = 0; i < 12000; i++)
        local_sum += histogram[i];
    total_windows += local_sum;
}
