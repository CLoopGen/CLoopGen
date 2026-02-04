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



void loop(){
    int i;
    for (i = 0; i < c->mc_pal_size && i < 5; i++) {
        int color_idx = mc_colors[i];
        int r = a64_palette[color_idx][0];
        int g = a64_palette[color_idx][1];
        int b = a64_palette[color_idx][2];
        c->mc_luma_vals[i] = (r * 299 + g * 589 + b * 112) / 1000; // Fixed-point approximation of coefficients
    }
    // Zero out remaining values if mc_pal_size < 5
    for (; i < 5; i++) {
        c->mc_luma_vals[i] = 0;
    }
}
