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
for (a = 0; a < 256; a++) {
    int next_luma = (i + 1 < c->mc_pal_size) ? c->mc_luma_vals[i + 1] : c->mc_luma_vals[i];
    int current_luma = c->mc_luma_vals[i];
    if (i < c->mc_pal_size - 1 && a == next_luma) {
        distance = next_luma - current_luma;
        int step;
        for (b = 0; b <= distance; b++) {
            step = b * 7 / distance;
            dither[current_luma + b] = (uint8_t)step;
        }
        i++;
    }
    if (i >= c->mc_pal_size - 1)
        dither[a] = 0;
    index1[a] = i;
    index2[a] = (i + 1 >= c->mc_pal_size) ? (c->mc_pal_size - 1) : (i + 1);
}
}
