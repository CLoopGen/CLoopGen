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
    for (ii = 0; ii < 4; ii++) {
        for (BLASLONG jj = 0; jj < 4; jj++) {
            BLASLONG idx = ii * 4 + jj;
            float *a_ptrs[] = {a01, a02, a03, a04, a05, a06, a07, a08,
                               a09, a10, a11, a12, a13, a14, a15, a16};
            b[0]  = *(a_ptrs[idx] + 0);
            b[1]  = *(a_ptrs[idx] + 1);
            b[2]  = *(a_ptrs[idx] + 2);
            b[3]  = *(a_ptrs[idx] + 3);
            b[4]  = *(a_ptrs[idx] + 4);
            b[5]  = *(a_ptrs[idx] + 5);
            b[6]  = *(a_ptrs[idx] + 6);
            b[7]  = *(a_ptrs[idx] + 7);
            b[8]  = *(a_ptrs[idx] + 8);
            b[9]  = *(a_ptrs[idx] + 9);
            b[10] = *(a_ptrs[idx] + 10);
            b[11] = *(a_ptrs[idx] + 11);
            b[12] = *(a_ptrs[idx] + 12);
            b[13] = *(a_ptrs[idx] + 13);
            b[14] = *(a_ptrs[idx] + 14);
            b[15] = *(a_ptrs[idx] + 15);
            b[16] = *(a_ptrs[idx] + 16);
            b[17] = *(a_ptrs[idx] + 17);
            b[18] = *(a_ptrs[idx] + 18);
            b[19] = *(a_ptrs[idx] + 19);
            b[20] = *(a_ptrs[idx] + 20);
            b[21] = *(a_ptrs[idx] + 21);
            b[22] = *(a_ptrs[idx] + 22);
            b[23] = *(a_ptrs[idx] + 23);
            b[24] = *(a_ptrs[idx] + 24);
            b[25] = *(a_ptrs[idx] + 25);
            b[26] = *(a_ptrs[idx] + 26);
            b[27] = *(a_ptrs[idx] + 27);
            b[28] = *(a_ptrs[idx] + 28);
            b[29] = *(a_ptrs[idx] + 29);
            b[30] = *(a_ptrs[idx] + 30);
            b[31] = *(a_ptrs[idx] + 31);
            b += 32;
        }
        a01 += 8; a02 += 8; a03 += 8; a04 += 8;
        a05 += 8; a06 += 8; a07 += 8; a08 += 8;
        a09 += 8; a10 += 8; a11 += 8; a12 += 8;
        a13 += 8; a14 += 8; a15 += 8; a16 += 8;
    }
}
