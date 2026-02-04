#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int INTFLOAT;

extern INTFLOAT *v;
extern  INTFLOAT *src0;
extern  INTFLOAT *src1;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int outer = 0; outer < 2; outer++) {
    for (i = 0; i < 64; i++) {
        if (outer == 0) {
            v[i] = (int)(16U + src0[i] - src1[63 - i]) >> 5;
        } else {
            v[127 - i] = (int)(16U + src0[i] + src1[63 - i]) >> 5;
        }
    }
}
}
