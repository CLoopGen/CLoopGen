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
    const int start_j = (k % 2 == 0) ? 0 : 1;
    for (j = start_j; j <= k; j += 1) {
        const int index = k - j;
        const int conv_term = ((pa[index] * pb[j]) % 2);
        if (index >= 0) {
            term = (term + conv_term) % 2;
        }
    }
    pt[k] = term;
}
}
