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

extern  uint8_t multi_dither_patterns[9][4][4];
extern  uint8_t interlaced_dither_patterns[9][8][4];
extern uint8_t *charset;
extern uint8_t *colrammap;
extern A64Context *c;
extern uint8_t row1;
extern uint8_t row2;
extern int charpos;
extern int x;
extern int y;
extern uint8_t pix;
extern int lowdiff;
extern int highdiff;
extern int *best_cb;
extern uint8_t index1[256];
extern uint8_t index2[256];
extern uint8_t dither[256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (charpos = 0; charpos < 256; ) {
        lowdiff = 0;
        highdiff = 0;
        for (y = 0; y < 8; y++) {
            row1 = 0;
            row2 = 0;
            for (x = 0; x < 4; x++) {
                int idx = y * 4 + x;
                pix = best_cb[idx];
                int i1 = index1[pix];
                int i2 = index2[pix];
                int dith = dither[pix];
                const uint8_t* pattern1 = interlaced_dither_patterns[dith][(y & 3) * 2 + 0];
                const uint8_t* pattern2 = interlaced_dither_patterns[dith][(y & 3) * 2 + 1];
                row1 <<= 2;
                row2 <<= 2;
                row1 |= 3 - ((pattern1[x & 3] ? i2 : i1) & 3);
                row2 |= 3 - ((pattern2[x & 3] ? i2 : i1) & 3);
                if (i1 >= 3)
                    highdiff += pix - c->mc_luma_vals[3];
                if (i1 < 1)
                    lowdiff += c->mc_luma_vals[1] - pix;
            }
            charset[y] = row1;
            charset[y + 2048] = row2;
        }
        if (highdiff > 0 && lowdiff > 0 && c->mc_use_5col) {
            int limit = lowdiff > highdiff ? c->mc_luma_vals[3] : c->mc_luma_vals[1];
            for (x = 0; x < 32; x++) {
                best_cb[x] = (limit > best_cb[x] ? best_cb[x] : limit);
            }
            // Do not increment charpos, retry same character
        } else {
            charpos++;
            best_cb += 32;
            charset += 8;
            colrammap[charpos-1] = (highdiff > 0);
        }
    }
}
