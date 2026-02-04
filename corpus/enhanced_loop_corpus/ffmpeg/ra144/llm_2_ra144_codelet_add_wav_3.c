#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern const int16_t ff_gain_val_tab[256][3];
extern const uint8_t ff_gain_exp_tab[256];
extern int n;
extern int skip_first;
extern int *m;
extern int i;
extern int v[3];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by reordering computation to access ff_gain_val_tab in row-major order
    // Here we assume that multiple n values could be processed, but since n is fixed, we simulate consecutive pattern 
    // by unrolling and accessing all i indices consecutively with direct indexing.
    int base_idx = n * 3;
    const int16_t *val_row = &ff_gain_val_tab[0][0] + base_idx;
    const int *m_ptr = m;
    int *v_ptr = v;
    
    for (i = !skip_first; i < 3; i++) {
        v_ptr[i] = (val_row[i] * (unsigned int)m_ptr[i]) >> ff_gain_exp_tab[n];
    }
}
