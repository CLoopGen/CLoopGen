#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *in_map;
extern  int n;
extern  int m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < m; i++) {
        int *in = &in_map[i * n + 1];
        int limit = (n - 1) >> 1;
        for (int j = 0; j < limit; j++) {
            if (j < n - j - 2) {
                int SWAP_tmp = in[n - j - 2];
                in[n - j - 2] = in[j];
                in[j] = SWAP_tmp;
            }
        }
    }
}
