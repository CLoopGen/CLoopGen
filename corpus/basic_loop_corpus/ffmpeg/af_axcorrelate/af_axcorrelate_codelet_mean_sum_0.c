#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float *in;
extern int size;
extern float mean_sum;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (int i = 0; i < size; i++)
    mean_sum += in[i];

}
