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
extern float *a09;
extern float *a10;
extern float *a11;
extern float *a12;
extern float *a13;
extern float *a14;
extern float *a15;
extern float *a16;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (ii = 0; ii < i; ii++) {
        for (BLASLONG j = 0; j < 16; j++) {
            BLASLONG idx = j * 2;
            float *a_ptr;
            switch(j) {
                case 0: a_ptr = a01; break;
                case 1: a_ptr = a02; break;
                case 2: a_ptr = a03; break;
                case 3: a_ptr = a04; break;
                case 4: a_ptr = a05; break;
                case 5: a_ptr = a06; break;
                case 6: a_ptr = a07; break;
                case 7: a_ptr = a08; break;
                case 8: a_ptr = a09; break;
                case 9: a_ptr = a10; break;
                case 10: a_ptr = a11; break;
                case 11: a_ptr = a12; break;
                case 12: a_ptr = a13; break;
                case 13: a_ptr = a14; break;
                case 14: a_ptr = a15; break;
                case 15: a_ptr = a16; break;
                default: a_ptr = a01;
            }
            b[idx + 0] = a_ptr[0];
            b[idx + 1] = a_ptr[1];
        }
        a01 += 2;
        a02 += 2;
        a03 += 2;
        a04 += 2;
        a05 += 2;
        a06 += 2;
        a07 += 2;
        a08 += 2;
        a09 += 2;
        a10 += 2;
        a11 += 2;
        a12 += 2;
        a13 += 2;
        a14 += 2;
        a15 += 2;
        a16 += 2;
        b += 32;
    }
}
