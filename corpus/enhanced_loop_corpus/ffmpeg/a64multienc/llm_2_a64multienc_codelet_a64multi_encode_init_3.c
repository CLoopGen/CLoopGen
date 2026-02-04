#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct AVLFG {
    unsigned int state[64];
    int index;
} AVLFG;

typedef struct A64Context {
    AVLFG randctx;
    int mc_lifetime;
    int mc_use_5col;
    unsigned int mc_frame_counter;
    int *mc_meta_charset;
    int *mc_charmap;
    int *mc_best_cb;
    int mc_luma_vals[5];
    uint8_t *mc_charset;
    uint8_t *mc_colram;
    uint8_t *mc_palette;
    int mc_pal_size;
    int64_t next_pts;
} A64Context;

extern  uint8_t a64_palette[16][3];
extern  uint8_t mc_colors[5];
extern A64Context *c;
extern int a;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided Memory Access Pattern
    // Instead of accessing mc_colors sequentially from 0 to mc_pal_size-1,
    // we traverse with a stride of 2, wrapping around if necessary.
    int stride = 2;
    int start = 0;
    int n = c->mc_pal_size;
    int count = 0;
    int idx = start;

    for (a = 0; a < n; a++) {
        idx = (start + a * stride) % n;
        c->mc_luma_vals[idx] = a64_palette[mc_colors[idx]][0] * 0.29999999999999999 + 
                               a64_palette[mc_colors[idx]][1] * 0.58999999999999997 + 
                               a64_palette[mc_colors[idx]][2] * 0.11;
    }
}
