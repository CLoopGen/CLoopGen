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
for (int j = 0; j < m; j += 2) {
    for (int i = 0; i < n; i++) {
        int base_i = i;
        int base_j = j;
        int comp_index = base_j * n + base_i;
        int mod_val = (base_i * m + base_j * n) % len;
        in_map[comp_index] = mod_val << mdct;

        if (j + 1 < m) {
            int next_j_idx = (j + 1) * n + i;
            int next_mod = (i * m + (j + 1) * n) % len;
            in_map[next_j_idx] = next_mod << mdct;
        }

        int out_idx = (i * m * m_inv + j * n * n_inv) % len;
        out_map[out_idx] = i * m + j;

        if (j + 1 < m) {
            int next_out_idx = (i * m * m_inv + (j + 1) * n * n_inv) % len;
            out_map[next_out_idx] = i * m + (j + 1);
        }
    }
}
}
