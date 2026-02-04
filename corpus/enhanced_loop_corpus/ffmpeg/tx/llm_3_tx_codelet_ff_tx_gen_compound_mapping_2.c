#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *in_map;
extern  int n;
extern  int m;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    for (int i = 0; i < m; i++) {
        int *base = &in_map[i * n];
        int stride = 2;
        int limit = (n - 1) >> 1;
        for (int j = 0; j < limit; j += stride) {
            for (int s = 0; s < stride && (j + s) < limit; s++) {
                int offset = j + s;
                int idx_forward = offset + 1;
                int idx_backward = n - offset - 2;
                int SWAP_tmp = base[idx_forward];
                base[idx_forward] = base[idx_backward];
                base[idx_backward] = SWAP_tmp;
            }
        }
    }
}
