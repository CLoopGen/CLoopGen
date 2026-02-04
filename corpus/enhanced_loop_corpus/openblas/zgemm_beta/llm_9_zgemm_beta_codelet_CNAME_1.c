#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG m;
extern BLASLONG n;
extern float beta_r;
extern float beta_i;
extern BLASLONG ldc;
extern BLASLONG i;
extern BLASLONG j;
extern float *c_offset;
extern float *c_offset1;
extern float atemp1;
extern float atemp2;
extern float atemp3;
extern float atemp4;
extern float btemp1;
extern float btemp2;
extern float btemp3;
extern float btemp4;
extern float ctemp1;
extern float ctemp2;
extern float ctemp3;
extern float ctemp4;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = n; j > 0; j -= 2) {
    c_offset1 = c_offset;
    c_offset += ldc;
    if (j >= 2) {
        for (i = 0; i < m; i++) {
            atemp1 = *(c_offset1 + 0);
            atemp2 = *(c_offset1 + 1);
            btemp1 = beta_r * atemp1;
            btemp2 = beta_i * atemp2;
            ctemp1 = btemp1 - btemp2;
            ctemp2 = beta_r * atemp2 + beta_i * atemp1;
            *(c_offset1 + 0) = ctemp1;
            *(c_offset1 + 1) = ctemp2;
            c_offset1 += 2;
        }
        c_offset1 = c_offset + ldc;
        for (i = 0; i < m; i++) {
            atemp1 = *(c_offset1 + 0);
            atemp2 = *(c_offset1 + 1);
            btemp1 = beta_r * atemp1;
            btemp2 = beta_i * atemp2;
            ctemp1 = btemp1 - btemp2;
            ctemp2 = beta_r * atemp2 + beta_i * atemp1;
            *(c_offset1 + 0) = ctemp1;
            *(c_offset1 + 1) = ctemp2;
            c_offset1 += 2;
        }
    } else {
        for (i = 0; i < m; i++) {
            atemp1 = *(c_offset1 + 0);
            atemp2 = *(c_offset1 + 1);
            btemp1 = beta_r * atemp1;
            btemp2 = beta_i * atemp2;
            ctemp1 = btemp1 - btemp2;
            ctemp2 = beta_r * atemp2 + beta_i * atemp1;
            *(c_offset1 + 0) = ctemp1;
            *(c_offset1 + 1) = ctemp2;
            c_offset1 += 2;
        }
    }
}
}
