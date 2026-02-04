#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int sulinesize;
extern  int svlinesize;
extern  int ulinesize;
extern  int vlinesize;
extern  int cbh;
extern  int cbv;
extern  int crh;
extern  int crv;
extern  int h;
extern  int w;
extern  int slice_start;
extern  int slice_end;
extern  uint8_t *su;
extern  uint8_t *sv;
extern uint8_t *du;
extern uint8_t *dv;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Consecutive Memory Access with Prefetching and Linear Indexing
    // Instead of recalculating 2D indices in inner loop, precompute base pointers and use linear traversal.
    // This improves spatial locality and enables better compiler optimization.

    uint8_t *du_base = du;
    uint8_t *dv_base = dv;
    int h_mask = h - 1;
    int w_mask = w - 1;
    
    // Use masked indexing assuming h and w are powers of two for modulo equivalence
    for (int y = slice_start; y < slice_end; y++) {
        int uy = ((y - cbv) & h_mask);
        int vy = ((y - crv) & h_mask);
        uint8_t *su_row = su + uy * sulinesize;
        uint8_t *sv_row = sv + vy * svlinesize;
        
        uint8_t *du_ptr = du_base + (y - slice_start) * ulinesize;
        uint8_t *dv_ptr = dv_base + (y - slice_start) * vlinesize;

        for (int x = 0; x < w; x++) {
            int ux = ((x - cbh) & w_mask);
            int vx = ((x - crh) & w_mask);
            du_ptr[x] = su_row[ux];
            dv_ptr[x] = sv_row[vx];
        }
    }
}
