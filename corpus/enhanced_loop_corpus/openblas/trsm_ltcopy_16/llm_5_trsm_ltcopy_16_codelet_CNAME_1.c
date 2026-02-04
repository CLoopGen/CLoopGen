#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG m;
extern BLASLONG lda;
extern float *b;
extern BLASLONG i;
extern BLASLONG ii;
extern BLASLONG jj;
extern BLASLONG k;
extern float *a1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < m; i++) {
    BLASLONG offset = ii - jj;
    int is_in_range = (offset >= 0) & (offset < 8);
    
    // Eliminate branching using conditional assignment logic
    float inv_diag = 1.F / (*(a1 + offset));
    for (k = 0; k < 8; k++) {
        float val = *(a1 + k);
        if (k == offset && is_in_range) {
            val = inv_diag;
        } else if (k > offset && is_in_range) {
            val = *(a1 + k);
        } // otherwise, val remains as *(a1 + k)
        *(b + k) = val;
    }

    b += 8;
    a1 += lda;
    ii++;
}
}
