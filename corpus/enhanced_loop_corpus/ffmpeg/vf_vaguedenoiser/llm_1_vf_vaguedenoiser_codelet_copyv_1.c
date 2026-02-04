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
    if (length > 0) {
        for (i = 0; i < length; i += 2) {
            p2[i] = *p1;
            p1 += stride1;
            if (i + 1 < length) {
                p2[i + 1] = *p1;
                p1 += stride1;
            }
        }
    }
}
