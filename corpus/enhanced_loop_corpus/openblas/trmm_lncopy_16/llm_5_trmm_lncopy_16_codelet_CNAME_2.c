#include <stdio.h>

typedef long BLASLONG;

extern float *b;
extern BLASLONG ii;
extern float *a01;
extern float *a02;
extern float *a03;
extern float *a04;
extern float *a05;
extern float *a06;
extern float *a07;
extern float *a08;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ii = 0; ii < 8; ii++) {
    b[0] = *(a01 + 0);
    if (ii >= 4) goto skip_middle;

    b[1] = *(a02 + 0);
    b[2] = *(a03 + 0);
skip_middle:
    b[3] = *(a04 + 0);
    b[4] = *(a05 + 0);

    if (ii < 6) {
        b[5] = *(a06 + 0);
    } else {
        b[5] = *(a07 + 0);
    }

    b[6] = *(a08 + 0);
    b[7] = *(a01 + 1); // Slight variation using next element

    a01++; a02++; a03++; a04++;
    a05++; a06++; a07++; a08++;
    b += 8;
}
}
