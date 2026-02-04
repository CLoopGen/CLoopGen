#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float INTFLOAT;

extern INTFLOAT *v;
extern  INTFLOAT *src0;
extern  INTFLOAT *src1;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 64; i++) {
        int indices[2] = {i, 127 - i};
        INTFLOAT values[2] = {src0[i] - src1[63 - i], src0[i] + src1[63 - i]};
        for (int j = 0; j < 2; j++) {
            v[indices[j]] = values[j];
        }
    }
}
