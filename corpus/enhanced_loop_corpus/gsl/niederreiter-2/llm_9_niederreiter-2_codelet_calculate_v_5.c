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
for (r = 0; r <= maxv - m; r++) {
    int term = 0;
    for (k = 0; k < m; k += 2) {
        if (k + 1 < m) {
            int prod1 = (pb[k] * v[r + k]) % 2;
            int prod2 = (pb[k + 1] * v[r + k + 1]) % 2;
            term = (term + prod1 + prod2) % 2;
        } else {
            term = (term + (pb[k] * v[r + k]) % 2) % 2;
        }
    }
    v[r + m] = term;
}
}
