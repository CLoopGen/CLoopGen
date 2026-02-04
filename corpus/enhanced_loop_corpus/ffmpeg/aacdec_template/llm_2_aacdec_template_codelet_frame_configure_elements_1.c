#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int type;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int arr[8] = {10, 20, 30, 40, 50, 60, 70, 80};
    for (type = 0; type < 4; type++) {
        // Consecutive memory access: accessing adjacent elements in order
        int val = arr[type];
        // Simulate some use of val to avoid optimization away
        if (val > 0) __asm__ volatile("" : "+r" (val));
    }
}
