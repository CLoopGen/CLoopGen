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
for (ii = 0; ii < 2; ii++) {
    float *addr1 = ao1 + ii * 2;
    float *addr2 = ao2 + ii * 2;
    float *addr3 = ao3 + ii * 2;
    float *addr4 = ao4 + ii * 2;
    b[0] = *addr1;
    b[1] = *addr2;
    b[2] = *addr3;
    b[3] = *addr4;
    b += 4;
}
}
