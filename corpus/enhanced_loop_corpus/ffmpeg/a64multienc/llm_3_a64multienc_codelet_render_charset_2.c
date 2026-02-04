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
    // Use indirect access via precomputed indices to modify memory access pattern
    int charpos_indices[256];
    int best_cb_base[256];
    int charset_base[256];

    // Precompute strided access offsets
    for (int i = 0; i < 256; i++) {
        charpos_indices[i] = i;
        best_cb_base[i] = i * 32;
        charset_base[i] = i * 8;
    }

    for (int idx = 0; idx < 256; idx++) {
        charpos = charpos_indices[idx];
        lowdiff = 0;
        highdiff = 0;
        int bcb = best_cb_base[charpos];
        int csb = charset_base[charpos];

        for (y = 0; y < 8; y++) {
            row1 = 0;
            row2 = 0;
            int y_offset = y * 4;

            for (x = 0; x < 4; x++) {
                int pixel_idx = bcb + y_offset + x;
                pix = best_cb[pixel_idx];

                if (index1[pix] >= 3)
                    highdiff += pix - c->mc_luma_vals[3];
                if (index1[pix] < 1)
                    lowdiff += c->mc_luma_vals[1] - pix;

                row1 <<= 2;
                row2 <<= 2;

                int dy = (y & 3) * 2;
                int dx = x & 3;
                int dith = dither[pix];

                if (interlaced_dither_patterns[dith][dy + 0][dx])
                    row1 |= 3 - (index2[pix] & 3);
                else
                    row1 |= 3 - (index1[pix] & 3);

                if (interlaced_dither_patterns[dith][dy + 1][dx])
                    row2 |= 3 - (index2[pix] & 3);
                else
                    row2 |= 3 - (index1[pix] & 3);
            }

            charset[csb + y] = row1;
            charset[csb + y + 2048] = row2;
        }

        if (highdiff > 0 && lowdiff > 0 && c->mc_use_5col) {
            if (lowdiff > highdiff) {
                for (int x = 0; x < 32; x++) {
                    int p = bcb + x;
                    best_cb[p] = (c->mc_luma_vals[3] > best_cb[p]) ? best_cb[p] : c->mc_luma_vals[3];
                }
            } else {
                for (int x = 0; x < 32; x++) {
                    int p = bcb + x;
                    best_cb[p] = (c->mc_luma_vals[1] > best_cb[p]) ? c->mc_luma_vals[1] : best_cb[p];
                }
            }
            idx--; // Compensate for loop increment to repeat iteration
        } else {
            colrammap[charpos] = (highdiff > 0);
        }
    }
}
