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
int factor, shift;
if (intra == 1) {
    factor = InvLevelScale4x4Chroma_Intra[uv][qp_rem][0][0];
} else {
    factor = InvLevelScale4x4Chroma_Inter[uv][qp_rem][0][0];
}
for (i = 0; i < 4; i++) {
    if (qp_per < 5) {
        shift = 5 - qp_per;
        m1[i] = (m5[i] * factor) >> shift;
    } else {
        shift = qp_per - 5;
        m1[i] = (m5[i] * factor) << shift;
    }
}
}
