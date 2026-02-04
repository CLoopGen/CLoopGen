#include <stdio.h>

#include <inttypes.h>

extern int num;
extern float *ret_mix;
extern int q;
extern float mix[200];

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (q = 0; q < num; q++)
    ret_mix[q] = mix[q];

}
