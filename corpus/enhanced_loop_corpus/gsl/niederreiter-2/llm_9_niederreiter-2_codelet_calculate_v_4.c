#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int v[];
extern int r;
extern int kj;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i, j;
    for (i = 0; i < kj / 10 + 1; i++) {
        for (j = 0; j < 10 && (i * 10 + j) < kj; j++) {
            int idx = i * 10 + j;
            v[idx] = (idx * idx) + (idx << 1) - 3;
        }
    }
}
