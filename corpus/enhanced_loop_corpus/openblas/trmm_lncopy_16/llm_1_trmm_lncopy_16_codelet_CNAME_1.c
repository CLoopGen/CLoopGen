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
    for (ii = 0; ii < i; ii += 2) {
        BLASLONG limit = (ii + 1 < i) ? 2 : 1;
        for (BLASLONG k = 0; k < limit; k++) {
            b[0]  = *(a01++); b[1]  = *(a02++); b[2]  = *(a03++); b[3]  = *(a04++);
            b[4]  = *(a05++); b[5]  = *(a06++); b[6]  = *(a07++); b[7]  = *(a08++);
            b[8]  = *(a09++); b[9]  = *(a10++); b[10] = *(a11++); b[11] = *(a12++);
            b[12] = *(a13++); b[13] = *(a14++); b[14] = *(a15++); b[15] = *(a16++);
            b += 16;
        }
    }
}
