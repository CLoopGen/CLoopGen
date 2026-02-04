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
        for (int i = 0; i < n; i++) {
            int idx_in = j * n + i;
            int val = ((i * m + j * n) % len) << mdct;
            in_map[idx_in] = val;
            out_map[(i * m * m_inv + j * n * n_inv) % len] = val >> mdct;
        }
    }
}
