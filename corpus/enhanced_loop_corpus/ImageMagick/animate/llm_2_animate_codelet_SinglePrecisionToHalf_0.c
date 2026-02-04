#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float alpha;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float alpha_arr[10];
    alpha_arr[0] = alpha;
    for (i = 1; i < 10; i++)
        alpha_arr[i] = alpha_arr[i-1] * alpha_arr[i-1];
    alpha = alpha_arr[9];
}
