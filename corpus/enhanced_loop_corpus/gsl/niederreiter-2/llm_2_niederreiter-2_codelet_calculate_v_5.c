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
    int base_index = r;
    for (k = 0; k < m; k++) {
        int v_index = base_index + k;
        term = (term + (pb[k] * v[v_index]) % 2) % 2;
    }
    v[base_index + m] = term;
}
}
