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
for (i = 0; i < 4; i++) {
    int index = i;
    if (qp_per < 5) {
        if (intra == 1)
            m1[index] = (m5[index] * InvLevelScale4x4Chroma_Intra[uv][qp_rem][index & 3][index & 3]) >> (5 - qp_per);
        else
            m1[index] = (m5[index] * InvLevelScale4x4Chroma_Inter[uv][qp_rem][index & 3][index & 3]) >> (5 - qp_per);
    } else {
        if (intra == 1)
            m1[index] = (m5[index] * InvLevelScale4x4Chroma_Intra[uv][qp_rem][index & 3][index & 3]) << (qp_per - 5);
        else
            m1[index] = (m5[index] * InvLevelScale4x4Chroma_Inter[uv][qp_rem][index & 3][index & 3]) << (qp_per - 5);
    }
}
}
