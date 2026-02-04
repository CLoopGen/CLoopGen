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
    for (i = 0; i < (m >> 1); i++) {
        BLASLONG base_idx = i * 4;
        atemp1 = *(c_offset1 + base_idx + 0);
        atemp2 = *(c_offset1 + base_idx + 1);
        atemp3 = *(c_offset1 + base_idx + 2);
        atemp4 = *(c_offset1 + base_idx + 3);
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
        *(c_offset1 + base_idx + 0) = ctemp1;
        *(c_offset1 + base_idx + 1) = ctemp2;
        *(c_offset1 + base_idx + 2) = ctemp3;
        *(c_offset1 + base_idx + 3) = ctemp4;
    }
    if (m & 1) {
        BLASLONG tail_idx = (m >> 1) * 4;
        atemp1 = *(c_offset1 + tail_idx + 0);
        atemp2 = *(c_offset1 + tail_idx + 1);
        btemp1 = beta_r * atemp1;
        btemp2 = beta_i * atemp2;
        btemp3 = beta_r * atemp2;
        btemp4 = beta_i * atemp1;
        ctemp1 = btemp1 - btemp2;
        ctemp2 = btemp3 + btemp4;
        *(c_offset1 + tail_idx + 0) = ctemp1;
        *(c_offset1 + tail_idx + 1) = ctemp2;
    }
}
}
