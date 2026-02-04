#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float alpha;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float arr[10];
    arr[0] = alpha;
    for (i = 1; i < 10; i++)
        arr[i] = arr[i-1] * arr[i-1];
    alpha = arr[9];
}
