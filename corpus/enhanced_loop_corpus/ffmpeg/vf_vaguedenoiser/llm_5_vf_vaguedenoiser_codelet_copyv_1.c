#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float *p1;
extern  int stride1;
extern float *p2;
extern  int length;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < length; i++) {
        if (i % 2 == 0) {
            p2[i] = *p1;
        } else {
            p2[i] = *p1 + 1.0f;
        }
        p1 += stride1;
    }
}
