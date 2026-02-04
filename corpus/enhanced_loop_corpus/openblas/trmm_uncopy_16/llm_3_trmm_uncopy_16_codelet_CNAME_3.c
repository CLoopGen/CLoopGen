#include <stdio.h>

typedef long BLASLONG;

extern float *b;
extern BLASLONG i;
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
for (ii = 0; ii < i; ii++) {
    float *addr_list[] = {a01, a02, a03, a04, a05, a06, a07, a08};
    for (BLASLONG j = 0; j < 8; j++) {
        b[j] = *(addr_list[j]);
    }
    a01++; a02++; a03++; a04++; a05++; a06++; a07++; a08++;
    b += 8;
}
}
