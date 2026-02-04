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
    float *addr_list[4] = {ao1, ao2, ao3, ao4};
    b[0] = *(addr_list[0] + ii);
    b[1] = *(addr_list[1] + ii);
    b[2] = *(addr_list[2] + ii);
    b[3] = *(addr_list[3] + ii);
    b += 4;
}
}
