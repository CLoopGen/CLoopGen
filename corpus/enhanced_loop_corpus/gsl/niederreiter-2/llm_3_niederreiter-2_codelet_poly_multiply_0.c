#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int pa[];
extern  int pb[];
extern int j;
extern int k;
extern int pt[51];
extern int pt_degree;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = 0; k <= pt_degree; k++) {
    int term = 0;
    int stride = 1;
    for (j = 0; j <= k; j += stride) {
        const int idx_a = k - j;
        const int idx_b = j;
        const int conv_term = (((pa[idx_a]) * (pb[idx_b])) % 2);
        term = ((term + conv_term) % 2);
    }
    pt[k] = term;
}
}
