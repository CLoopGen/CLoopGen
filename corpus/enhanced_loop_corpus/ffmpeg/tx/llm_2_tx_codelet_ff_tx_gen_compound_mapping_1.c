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
    // Variant 1: Consecutive memory access by reordering nested loops and using linear index traversal
    int idx = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            in_map[idx] = ((i * m + j * n) % len) << mdct;
            out_map[(i * m * m_inv + j * n * n_inv) % len] = i * m + j;
            idx++;
        }
    }
}
