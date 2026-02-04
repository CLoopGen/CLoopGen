#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *out;
extern int stride;
extern int width;
extern int height;
extern int bpp;
extern uint8_t cols[4];
extern uint8_t grps[4];
extern uint32_t col;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (y = 0; y < height; y += 2) {
        uint8_t base_grp = grps ? grps[3 * (y >> 1)] : 0;
        for (x = 0; x < width; x += 2) {
            if (grps) {
                cols[0] = base_grp;
                cols[1] = grps[(x >> 1) + 1];
            }
            uint8_t index = col & ((1 << bpp) - 1);
            out[x + y * stride] = cols[index];
            col >>= bpp;
            if (x + 1 < width) {
                index = col & ((1 << bpp) - 1);
                out[x + 1 + y * stride] = cols[index];
                col >>= bpp;
            }
            if (y + 1 < height) {
                index = col & ((1 << bpp) - 1);
                out[x + (y + 1) * stride] = cols[index];
                col >>= bpp;
                if (x + 1 < width) {
                    index = col & ((1 << bpp) - 1);
                    out[x + 1 + (y + 1) * stride] = cols[index];
                    col >>= bpp;
                }
            }
        }
    }
}
