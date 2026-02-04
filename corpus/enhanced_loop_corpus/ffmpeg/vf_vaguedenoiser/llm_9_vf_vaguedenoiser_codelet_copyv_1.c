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
    for (i = 0; i < length * 2; i++) {
        int idx = i / 2;
        p2[idx] = (i % 2 == 0) ? *p1 : (*p1 + *(p1 + stride1)) * 0.5f;
        if (i % 2 == 1) {
            p1 += stride1;
        }
    }
}
