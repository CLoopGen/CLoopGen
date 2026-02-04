#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float alpha;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float alpha_arr[20];
    for (i = 0; i < 10; i++)
        alpha_arr[2*i] = alpha * alpha;
    alpha = alpha_arr[18]; // Last updated value at index 18
}
