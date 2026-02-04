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
    BLASLONG diff = ii - jj;
    int copy_count = (diff >= 4) ? 4 : (diff > 0) ? diff : 0;

    switch (copy_count) {
        case 4:
            *(b + 0) = *(a1 + 0);
            *(b + 1) = *(a1 + 1);
            *(b + 2) = *(a1 + 2);
            *(b + 3) = *(a1 + 3);
            break;
        case 3:
            *(b + 2) = *(a1 + 2);
            // fall through
        case 2:
            *(b + 1) = *(a1 + 1);
            // fall through
        case 1:
            *(b + 0) = *(a1 + 0);
            if (diff < 4) {
                *(b + diff) = (1.F / (*(a1 + diff)));
            }
            break;
        default:
            if (diff < 4 && diff >= 0) {
                *(b + diff) = (1.F / (*(a1 + diff)));
            }
            break;
    }

    b += 4;
    a1 += lda;
    ii++;
}
}
