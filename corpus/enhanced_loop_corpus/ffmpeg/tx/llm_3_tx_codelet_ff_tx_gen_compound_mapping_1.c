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
    // Variant 2: Strided memory access with indirect indexing via pointer arithmetic and fixed stride jumps
    int stride = len / (m * n) + 1; // Artificial stride to scatter access
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            int offset_in = (j * n + i) * stride % len;
            int offset_out = (i * m * m_inv + j * n * n_inv) * stride % len;
            in_map[offset_in] = ((i * m + j * n) % len) << mdct;
            out_map[offset_out] = i * m + j;
        }
    }
}
