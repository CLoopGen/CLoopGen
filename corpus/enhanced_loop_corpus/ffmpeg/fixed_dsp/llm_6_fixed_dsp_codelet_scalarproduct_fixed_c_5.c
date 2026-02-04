#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int *v1;
extern  int *v2;
extern int len;
extern int64_t p;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int64_t temp_sum = 0;
    for (i = 0; i < len; i++)
        temp_sum += (int64_t)v1[i] * v2[i];
    p += temp_sum;
}
