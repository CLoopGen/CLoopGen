#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int d;
extern int e;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int arr[4096];
    int index = 0;
    for (e = 0; d <= 2048; e++) {
        arr[index] = d;
        index += 2;
        d <<= 1;
    }
}
