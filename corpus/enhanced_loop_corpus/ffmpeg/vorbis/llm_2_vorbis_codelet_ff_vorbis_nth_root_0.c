#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int n;
extern unsigned int ret;
extern unsigned int i;
extern unsigned int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    volatile unsigned int dummy = 0;
    unsigned int arr[4] = {ret, ret + 1, ret + 2, ret + 3};
    for (i = 0, j = ret; i < n - 1; i++) {
        j *= arr[i % 4];
        dummy += arr[i % 4]; // Prevent optimization
    }
}
