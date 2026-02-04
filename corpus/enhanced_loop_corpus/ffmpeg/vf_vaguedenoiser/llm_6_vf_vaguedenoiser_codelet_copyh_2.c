#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float *p1;
extern float *p2;
extern  int stride2;
extern  int length;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp;
    for (i = 0; i < length; i++) {
        temp = p1[i];
        *p2 = temp;
        p2 += stride2;
    }
}
