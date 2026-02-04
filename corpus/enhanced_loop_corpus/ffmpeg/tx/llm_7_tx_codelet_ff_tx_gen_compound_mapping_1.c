#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *in_map;
extern int *out_map;
extern  int n;
extern  int m;
extern  int len;
extern  int m_inv;
extern  int n_inv;
extern  int mdct;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int j = 0; j < m; j++) {
        int base_out = j * n * n_inv % len;
        for (int i = 0; i < n; i++) {
            int linear_idx = i * m + j;
            int in_index = j * n + i;
            int out_index = (i * m * m_inv + base_out) % len;
            in_map[in_index] = (linear_idx % len) << mdct;
            out_map[out_index] = linear_idx;
        }
    }
}
