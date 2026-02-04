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
    int temp[4];
    for (i = 0; i < 4; ++i) {
        if (qp_per < 5) {
            if (intra == 1)
                temp[i] = (m5[i] * InvLevelScale4x4Chroma_Intra[uv][qp_rem][0][0]) >> (5 - qp_per);
            else
                temp[i] = (m5[i] * InvLevelScale4x4Chroma_Inter[uv][qp_rem][0][0]) >> (5 - qp_per);
        } else {
            if (intra == 1)
                temp[i] = (m5[i] * InvLevelScale4x4Chroma_Intra[uv][qp_rem][0][0]) << (qp_per - 5);
            else
                temp[i] = (m5[i] * InvLevelScale4x4Chroma_Inter[uv][qp_rem][0][0]) << (qp_per - 5);
        }
    }
    // Introduce WAW dependency by writing to m1 after temp is fully computed
    for (i = 0; i < 4; ++i) {
        m1[i] = temp[i];
    }
}
