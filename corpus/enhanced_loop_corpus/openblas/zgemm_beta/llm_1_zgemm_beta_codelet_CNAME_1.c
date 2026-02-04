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
for (j = n; j > 0; j--) {
    c_offset1 = c_offset;
    c_offset += ldc;
    for (BLASLONG jj = 0; jj < m; jj++) {
        if ((jj % 2 == 0) && (jj + 1 < m)) {
            atemp1 = *(c_offset1 + 0);
            atemp2 = *(c_offset1 + 1);
            atemp3 = *(c_offset1 + 2);
            atemp4 = *(c_offset1 + 3);
            btemp1 = beta_r * atemp1;
            btemp2 = beta_i * atemp2;
            btemp3 = beta_r * atemp2;
            btemp4 = beta_i * atemp1;
            ctemp1 = btemp1 - btemp2;
            ctemp2 = btemp3 + btemp4;
            btemp1 = beta_r * atemp3;
            btemp2 = beta_i * atemp4;
            btemp3 = beta_r * atemp4;
            btemp4 = beta_i * atemp3;
            ctemp3 = btemp1 - btemp2;
            ctemp4 = btemp3 + btemp4;
            *(c_offset1 + 0) = ctemp1;
            *(c_offset1 + 1) = ctemp2;
            *(c_offset1 + 2) = ctemp3;
            *(c_offset1 + 3) = ctemp4;
            c_offset1 += 4;
            jj += 1; 
        } else {
            atemp1 = *(c_offset1 + 0);
            atemp2 = *(c_offset1 + 1);
            btemp1 = beta_r * atemp1;
            btemp2 = beta_i * atemp2;
            btemp3 = beta_r * atemp2;
            btemp4 = beta_i * atemp1;
            ctemp1 = btemp1 - btemp2;
            ctemp2 = btemp3 + btemp4;
            *(c_offset1 + 0) = ctemp1;
            *(c_offset1 + 1) = ctemp2;
            c_offset1 += 2;
        }
    }
}
}
