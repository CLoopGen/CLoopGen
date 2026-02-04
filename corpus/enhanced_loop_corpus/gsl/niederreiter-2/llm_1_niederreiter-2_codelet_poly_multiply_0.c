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
int k, j;
if (pt_degree >= 0) {
    for (k = 0; k <= pt_degree; k++) {
        int term = 0;
        for (j = k; j >= 0; j--) {
            const int conv_term = ((pa[k - j] * pb[j]) % 2);
            term = (term + conv_term) % 2;
        }
        pt[k] = term;
    }
}
}
