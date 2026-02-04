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
    // Variant 1: Consecutive memory access with reverse traversal and strided update
    for (a = 255; a >= 0; a--) {
        int next_i = i + 1;
        if (i < c->mc_pal_size - 1 && a == c->mc_luma_vals[next_i]) {
            distance = c->mc_luma_vals[next_i] - c->mc_luma_vals[i];
            // Unroll the inner loop partially to create consecutive writes
            for (b = 0; b <= distance; b += 4) {
                int pos0 = c->mc_luma_vals[i] + b;
                int pos1 = pos0 + 1;
                int pos2 = pos0 + 2;
                int pos3 = pos0 + 3;
                if (pos0 <= 255) dither[pos0] = b * 7 / distance;
                if (pos1 <= 255 && (b+1) <= distance) dither[pos1] = (b+1) * 7 / distance;
                if (pos2 <= 255 && (b+2) <= distance) dither[pos2] = (b+2) * 7 / distance;
                if (pos3 <= 255 && (b+3) <= distance) dither[pos3] = (b+3) * 7 / distance;
            }
            i++;
        }
        if (i >= c->mc_pal_size - 1)
            dither[a] = 0;
        index1[a] = i;
        index2[a] = (next_i > c->mc_pal_size - 1) ? (c->mc_pal_size - 1) : next_i;
    }
}
