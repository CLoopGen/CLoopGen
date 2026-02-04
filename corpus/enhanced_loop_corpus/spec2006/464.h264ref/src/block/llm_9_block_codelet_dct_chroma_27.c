#include <stdio.h>

#include <inttypes.h>

extern int InvLevelScale4x4Chroma_Intra[2][6][4][4];
extern int InvLevelScale4x4Chroma_Inter[2][6][4][4];
extern int uv;
extern int i;
extern int m1[4];
extern int m5[4];
extern int qp_per;
extern int qp_rem;
extern int intra;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 4; i += 2) {
    int temp_intra = InvLevelScale4x4Chroma_Intra[uv][qp_rem][0][0];
    int temp_inter = InvLevelScale4x4Chroma_Inter[uv][qp_rem][0][0];
    int shift_val = (qp_per < 5) ? (5 - qp_per) : (qp_per - 5);
    int scale_intra = (qp_per < 5) ? ((m5[i] * temp_intra) >> shift_val) : ((m5[i] * temp_intra) << shift_val);
    int scale_inter = (qp_per < 5) ? ((m5[i] * temp_inter) >> shift_val) : ((m5[i] * temp_inter) << shift_val);
    m1[i] = (intra == 1) ? scale_intra : scale_inter;

    if (i + 1 < 4) {
        int scale_intra_next = (qp_per < 5) ? ((m5[i+1] * temp_intra) >> shift_val) : ((m5[i+1] * temp_intra) << shift_val);
        int scale_inter_next = (qp_per < 5) ? ((m5[i+1] * temp_inter) >> shift_val) : ((m5[i+1] * temp_inter) << shift_val);
        m1[i+1] = (intra == 1) ? scale_intra_next : scale_inter_next;
    }
}
}
