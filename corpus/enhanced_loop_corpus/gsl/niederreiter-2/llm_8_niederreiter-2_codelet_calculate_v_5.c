#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int pb[];
extern int v[];
extern int maxv;
extern int m;
extern int r;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (r = 0; r <= maxv - m; r += 2) {
    int term1 = 0, term2 = 0;
    for (k = 0; k < m; k++) {
        term1 = (term1 + ((pb[k] * v[r + k]) % 2)) % 2;
        if (r + 1 <= maxv - m) {
            term2 = (term2 + ((pb[k] * v[r + 1 + k]) % 2)) % 2;
        }
    }
    v[r + m] = term1;
    if (r + 1 <= maxv - m) {
        v[r + 1 + m] = term2;
    }
}
}
