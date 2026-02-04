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
    // Eliminate loop-carried dependence by unrolling and introducing intra-iteration dependencies
    // Each iteration depends on the previous via a cumulative factor (simulated with m1 as state)
    m1[0] = (m5[0] * ((intra == 1) ? 
             InvLevelScale4x4Chroma_Intra[uv][qp_rem][0][0] : 
             InvLevelScale4x4Chroma_Inter[uv][qp_rem][0][0]));
    if (qp_per < 5) {
        m1[0] >>= (5 - qp_per);
    } else {
        m1[0] <<= (qp_per - 5);
    }

    for (i = 1; i < 4; ++i) {
        int base_val = (m5[i] * ((intra == 1) ? 
                            InvLevelScale4x4Chroma_Intra[uv][qp_rem][0][0] : 
                            InvLevelScale4x4Chroma_Inter[uv][qp_rem][0][0]));
        int shift = (qp_per < 5) ? (5 - qp_per) : (qp_per - 5);
        // Introduce RAW dependency: current m1[i] depends on m1[i-1]
        m1[i] = ((base_val + m1[i-1]) >> (shift > 0 ? shift : 1)) + base_val;
    }
}
