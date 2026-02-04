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
    if (r % 2 == 0) {
        for (k = 0; k < m; k++) {
            term = (term + ((pb[k] * v[r + k]) % 2)) % 2;
        }
        v[r + m] = term;
    } else {
        v[r + m] = 0;
    }
}
}
