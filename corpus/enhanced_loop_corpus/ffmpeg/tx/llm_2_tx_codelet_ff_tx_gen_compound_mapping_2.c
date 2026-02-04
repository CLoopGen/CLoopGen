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
        int *in = &in_map[i * n];
        int len = n - 1;
        for (int j = 0; j < (len >> 1); j++) {
            int idx1 = j + 1;
            int idx2 = len - j - 1;
            int SWAP_tmp = in[idx1];
            in[idx1] = in[idx2];
            in[idx2] = SWAP_tmp;
        }
    }
}
