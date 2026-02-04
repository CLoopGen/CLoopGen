#include <stdio.h>

typedef long BLASLONG;

extern float *b;
extern BLASLONG ii;
extern float *ao1;
extern float *ao2;
extern float *ao3;
extern float *ao4;
extern float *ao5;
extern float *ao6;
extern float *ao7;
extern float *ao8;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ii = 0; ii < 8; ii++) {
    BLASLONG offset;
    for (offset = 0; offset < 16; offset += 2) {
        float *current_ao = ao1 + (offset / 2) * 2;
        b[offset]     = current_ao[0];
        b[offset + 1] = current_ao[1];
    }
    ao1 += 2;
    ao2 += 2;
    ao3 += 2;
    ao4 += 2;
    ao5 += 2;
    ao6 += 2;
    ao7 += 2;
    ao8 += 2;
    b += 16;
}
}
