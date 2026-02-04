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
    BLASLONG stride = 2;
    BLASLONG vector_count = m / 2;
    for (i = 0; i < vector_count; i++) {
        BLASLONG idx0 = i * stride;
        BLASLONG idx1 = idx0 + 1;
        float* addr0 = c_offset1 + (idx0 << 1);
        float* addr1 = c_offset1 + (idx1 << 1);
        atemp1 = *addr0;
        atemp2 = *(addr0 + 1);
        atemp3 = *addr1;
        atemp4 = *(addr1 + 1);
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
        *addr0 = ctemp1;
        *(addr0 + 1) = ctemp2;
        *addr1 = ctemp3;
        *(addr1 + 1) = ctemp4;
    }
    if (m & 1) {
        BLASLONG tail_base = (m - 1) * 2;
        float* tail_addr = c_offset1 + tail_base;
        atemp1 = *tail_addr;
        atemp2 = *(tail_addr + 1);
        btemp1 = beta_r * atemp1;
        btemp2 = beta_i * atemp2;
        btemp3 = beta_r * atemp2;
        btemp4 = beta_i * atemp1;
        ctemp1 = btemp1 - btemp2;
        ctemp2 = btemp3 + btemp4;
        *tail_addr = ctemp1;
        *(tail_addr + 1) = ctemp2;
    }
}
}
