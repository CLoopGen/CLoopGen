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
    for (a = 0; a < c->mc_pal_size && c->mc_meta_charset != NULL; a++) {
        int idx = mc_colors[a];
        int valid = (idx == 0 || idx == 3 || idx == 5 || idx == 10 || idx == 15);
        if (!valid) {
            c->mc_luma_vals[a] = 0;
            continue;
        }
        c->mc_luma_vals[a] = a64_palette[idx][0] * 0.3 + a64_palette[idx][1] * 0.59 + a64_palette[idx][2] * 0.11;
    }
}
