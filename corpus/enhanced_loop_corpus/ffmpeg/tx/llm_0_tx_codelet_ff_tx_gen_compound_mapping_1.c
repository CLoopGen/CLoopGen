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
    int base_jn = j * n;
    int base_j = j;
    for (int i = 0; i < n; i++) {
        int index_in = j * n + i;
        int index_out = (i * m * m_inv + base_j * n * n_inv) % len;
        in_map[index_in] = ((i * m + base_jn) % len) << mdct;
        out_map[index_out] = i * m + base_j;
    }
}
}
