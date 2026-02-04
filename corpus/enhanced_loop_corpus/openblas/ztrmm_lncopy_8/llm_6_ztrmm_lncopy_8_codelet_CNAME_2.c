#include <stdio.h>

typedef long BLASLONG;

extern float *b;
extern BLASLONG ii;
extern float *ao1;
extern float *ao2;
extern float *ao3;
extern float *ao4;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    BLASLONG temp_offset;
    for (ii = 0; ii < 4; ii++) {
        temp_offset = ii * 2;
        b[0] = ao1[temp_offset + 0];
        b[1] = ao1[temp_offset + 1];
        b[2] = ao2[temp_offset + 0];
        b[3] = ao2[temp_offset + 1];
        b[4] = ao3[temp_offset + 0];
        b[5] = ao3[temp_offset + 1];
        b[6] = ao4[temp_offset + 0];
        b[7] = ao4[temp_offset + 1];
        b += 8;
    }
    ao1 += 8;
    ao2 += 8;
    ao3 += 8;
    ao4 += 8;
}
