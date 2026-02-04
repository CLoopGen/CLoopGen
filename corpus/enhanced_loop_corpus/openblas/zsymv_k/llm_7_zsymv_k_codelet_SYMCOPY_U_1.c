#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG m;
extern float *a;
extern BLASLONG lda;
extern BLASLONG is;
extern BLASLONG js;
extern float *aa1;
extern float *aa2;
extern float *b1;
extern float *b2;
extern float *bb1;
extern float *bb2;
extern float *cc1;
extern float *cc2;
extern float a11;
extern float a12;
extern float a21;
extern float a22;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (js = 0; js < m; js += 2) {
    aa1 = a + 0 * lda;
    aa2 = a + 1 * lda;
    a += 2 * lda;
    bb1 = b1 + 0 * m;
    bb2 = b1 + 1 * m;
    b1 += 2 * m;
    cc1 = b2 + 0 * m;
    cc2 = b2 + 1 * m;
    b2 += 2;
    if (m - js >= 2) {
        // Eliminate some loop-carried dependencies by unconditionally advancing pointers early
        float *local_bb1 = bb1, *local_bb2 = bb2, *local_cc1 = cc1, *local_cc2 = cc2;
        float *local_aa1 = aa1, *local_aa2 = aa2;
        for (is = 0; is < js; is += 2) {
            // Load all data first — reduce interleaving (weaker RAW within loop body)
            a11 = local_aa1[0];
            a21 = local_aa1[1];
            a12 = local_aa2[0];
            a22 = local_aa2[1];
            // Perform all stores using pre-loaded data — break memory ordering assumptions
            local_bb1[0] = a11;
            local_bb1[1] = a21;
            local_bb2[0] = a12;
            local_bb2[1] = a22;
            local_cc1[0] = a11;
            local_cc1[1] = a12;
            local_cc2[0] = a21;
            local_cc2[1] = a22;
            // Advance all pointers at end of iteration — reduces intra-loop dependency chains
            local_aa1 += 2;
            local_aa2 += 2;
            local_bb1 += 2;
            local_bb2 += 2;
            local_cc1 += 2 * m;
            local_cc2 += 2 * m;
        }
        // Final stores using original pointers (no loop-carried dependency from inner loop)
        a11 = *(aa1 + 0);
        a12 = *(aa2 + 0);
        a22 = *(aa2 + 1);
        *(bb1 + 0) = a11;
        *(bb1 + 1) = a12;
        *(bb2 + 0) = a12;
        *(bb2 + 1) = a22;
    }
    if (m - js == 1) {
        float *local_bb1 = bb1, *local_cc1 = cc1, *local_cc2 = cc2;
        float *local_aa1 = aa1;
        for (is = 0; is < js; is += 2) {
            a11 = local_aa1[0];
            a21 = local_aa1[1];
            local_aa1 += 2;
            local_bb1[0] = a11;
            local_bb1[1] = a21;
            local_cc1[0] = a11;
            local_cc2[0] = a21;
            local_bb1 += 2;
            local_cc1 += 2 * m;
            local_cc2 += 2 * m;
        }
        a11 = *(aa1 + 0);
        *(bb1 + 0) = a11;
    }
}
}
