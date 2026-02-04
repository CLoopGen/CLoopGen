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
for (i = 0; i < 64; i++) {
    int j = 63 - i;
    for (int k = 0; k < 1; k++) {  // Artificially nested single-iteration loop
        v[i] = (int)(16U + src0[i] - src1[j]) >> 5;
        v[127 - i] = (int)(16U + src0[i] + src1[j]) >> 5;
    }
}
}
