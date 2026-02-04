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
int i_inner;
for (i = 0; i < 8; i++) {
    int idx = i >> 1; // effectively process every two iterations for the same m5/m1 index
    if (idx < 4) {
        if (qp_per < 5) {
            if (intra == 1)
                m1[idx] = (m5[idx] * InvLevelScale4x4Chroma_Intra[uv][qp_rem][0][0] + 1) >> (5 - qp_per);
            else
                m1[idx] = (m5[idx] * InvLevelScale4x4Chroma_Inter[uv][qp_rem][0][0] + 1) >> (5 - qp_per);
        } else {
            if (intra == 1)
                m1[idx] = (m5[idx] * InvLevelScale4x4Chroma_Intra[uv][qp_rem][0][0] + 1) << (qp_per - 5);
            else
                m1[idx] = (m5[idx] * InvLevelScale4x4Chroma_Inter[uv][qp_rem][0][0] + 1) << (qp_per - 5);
        }
    }
}
}
