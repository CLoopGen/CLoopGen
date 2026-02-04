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
    for (int j = 0; j < 1; j++) {
        for (i = 0; i < 4; i++) {
            if (qp_per < 5) {
                if (intra == 1)
                    m1[i] = (m5[i] * InvLevelScale4x4Chroma_Intra[uv][qp_rem][0][0]) >> (5 - qp_per);
                else
                    m1[i] = (m5[i] * InvLevelScale4x4Chroma_Inter[uv][qp_rem][0][0]) >> (5 - qp_per);
            } else {
                if (intra == 1)
                    m1[i] = (m5[i] * InvLevelScale4x4Chroma_Intra[uv][qp_rem][0][0]) << (qp_per - 5);
                else
                    m1[i] = (m5[i] * InvLevelScale4x4Chroma_Inter[uv][qp_rem][0][0]) << (qp_per - 5);
            }
        }
    }
}
