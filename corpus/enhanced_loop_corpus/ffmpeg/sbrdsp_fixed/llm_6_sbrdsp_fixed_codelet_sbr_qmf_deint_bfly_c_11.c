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
    INTFLOAT temp1, temp2;
    for (i = 0; i < 64; i++) {
        temp1 = (int)(16U + src0[i] - src1[63 - i]) >> 5;
        temp2 = (int)(16U + src0[i] + src1[63 - i]) >> 5;
        v[i] = temp1;
        v[127 - i] = temp2;
    }
}
