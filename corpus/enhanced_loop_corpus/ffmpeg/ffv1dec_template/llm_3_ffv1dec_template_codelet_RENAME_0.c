#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int arr[8] = {10, 20, 30, 40, 50, 60, 70, 80};
    int indices[] = {0, 2, 4, 6}; // Indirect access via index array
    for (x = 0; x < 4; x++) {
        // Indirect memory access: using an index array to fetch values
        int val = arr[indices[x]];
        // Simulate some use to prevent optimization away
        if (val > 0) __asm__ volatile("" : "+r" (val));
    }
}
