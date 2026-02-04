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
    for (charpos = 0; charpos < 256; charpos++) {
        lowdiff = 0;
        highdiff = 0;
        uint8_t *charset_offset = charset + charpos * 8;
        int *best_cb_offset = best_cb + charpos * 32;

        for (y = 0; y < 8; y++) {
            row1 = 0;
            row2 = 0;
            int base_idx = y * 4;
            const uint8_t *dither_row_low = interlaced_dither_patterns[dither[best_cb_offset[base_idx + 0]]][(y & 3) * 2 + 0];
            const uint8_t *dither_row_high = interlaced_dither_patterns[dither[best_cb_offset[base_idx + 0]]][(y & 3) * 2 + 1];

            for (x = 0; x < 4; x++) {
                pix = best_cb_offset[base_idx + x];
                if (index1[pix] >= 3)
                    highdiff += pix - c->mc_luma_vals[3];
                if (index1[pix] < 1)
                    lowdiff += c->mc_luma_vals[1] - pix;
                row1 <<= 2;
                row2 <<= 2;

                int dith_x = x & 3;
                int idx1 = index1[pix] & 3;
                int idx2 = index2[pix] & 3;
                row1 |= 3 - (dither_row_low[dith_x] ? idx2 : idx1);
                row2 |= 3 - (dither_row_high[dith_x] ? idx2 : idx1);
            }
            charset_offset[y + 0] = row1;
            charset_offset[y + 2048] = row2;
        }

        if (highdiff > 0 && lowdiff > 0 && c->mc_use_5col) {
            if (lowdiff > highdiff) {
                for (x = 0; x < 32; x++) {
                    int val = best_cb_offset[x];
                    best_cb_offset[x] = (c->mc_luma_vals[3] < val) ? val : c->mc_luma_vals[3];
                }
            } else {
                for (x = 0; x < 32; x++) {
                    int val = best_cb_offset[x];
                    best_cb_offset[x] = (c->mc_luma_vals[1] > val) ? c->mc_luma_vals[1] : val;
                }
            }
            charpos--;
        } else {
            colrammap[charpos] = (highdiff > 0);
        }
    }
}
