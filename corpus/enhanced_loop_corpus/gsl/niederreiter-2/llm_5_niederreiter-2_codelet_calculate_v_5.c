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
    for (k = 0; k < m; k++) {
        if (pb[k] != 0 && v[r + k] != 0) {
            term = (term + 1) % 2;
        }
    }
    v[r + m] = term;
}
}
