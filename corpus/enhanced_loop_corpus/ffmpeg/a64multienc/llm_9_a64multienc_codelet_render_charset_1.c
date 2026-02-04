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

extern A64Context *c;
extern int a;
extern int b;
extern uint8_t index1[256];
extern uint8_t index2[256];
extern uint8_t dither[256];
extern int i;
extern int distance;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int fast_path = (c->mc_pal_size - 1) <= 0;
if (fast_path) {
    for (a = 0; a < 256; a++) {
        dither[a] = 0;
        index1[a] = 0;
        index2[a] = 0;
    }
    return;
}

int threshold = c->mc_luma_vals[i + 1];
for (a = 0; a < 256; ++a) {
    if (!fast_path && i < c->mc_pal_size - 1 && a == threshold) {
        distance = c->mc_luma_vals[i + 1] - c->mc_luma_vals[i];
        int step_val = (8 - 1);
        int temp = 0;
        for (b = 0; b <= distance; ++b) {
            dither[c->mc_luma_vals[i] + b] = (uint8_t)((temp + (step_val / 2)) / distance); // Rounded division
            temp += step_val;
        }
        i++;
        if (i < c->mc_pal_size - 1)
            threshold = c->mc_luma_vals[i + 1];
        else
            fast_path = 1;
    }
    index1[a] = fast_path ? (c->mc_pal_size - 1) : i;
    index2[a] = fast_path ? (c->mc_pal_size - 1) : ((i + 1) > (c->mc_pal_size - 1) ? (c->mc_pal_size - 1) : (i + 1));
    if (fast_path)
        dither[a] = 0;
}
}
