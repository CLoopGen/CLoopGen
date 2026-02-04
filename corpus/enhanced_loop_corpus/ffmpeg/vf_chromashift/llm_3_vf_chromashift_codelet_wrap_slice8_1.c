#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int sulinesize;
extern  int svlinesize;
extern  int ulinesize;
extern  int vlinesize;
extern  int cbh;
extern  int cbv;
extern  int crh;
extern  int crv;
extern  int h;
extern  int w;
extern  int slice_start;
extern  int slice_end;
extern  uint8_t *su;
extern  uint8_t *sv;
extern uint8_t *du;
extern uint8_t *dv;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Strided Memory Access with Transposed Output Layout
    // Simulate a strided access pattern by writing output in non-consecutive locations.
    // This variant assumes that `du` and `dv` are now accessed with stride equal to `ulinesize` / `vlinesize`
    // but processes pixels in column-major order to change memory access characteristics.

    int h_mask = (h & (h - 1)) == 0 ? h - 1 : 0; // Only use bit mask if h is power of two
    int w_mask = (w & (w - 1)) == 0 ? w - 1 : 0;

    for (int x = 0; x < w; x++) {
        for (int y = slice_start; y < slice_end; y++) {
            int uy = (y - cbv);
            int vy = (y - crv);
            if (h_mask) {
                uy &= h_mask;
                vy &= h_mask;
            } else {
                uy %= h; if (uy < 0) uy += h;
                vy %= h; if (vy < 0) vy += h;
            }

            int ux = (x - cbh);
            int vx = (x - crh);
            if (w_mask) {
                ux &= w_mask;
                vx &= w_mask;
            } else {
                ux %= w; if (ux < 0) ux += w;
                vx %= w; if (vx < 0) vx += w;
            }

            // Strided write: each column written consecutively across rows
            du[(y - slice_start) * ulinesize + x] = su[ux + uy * sulinesize];
            dv[(y - slice_start) * vlinesize + x] = sv[vx + vy * svlinesize];
        }
    }

    // Final pointer update to maintain interface consistency (caller expects du/dv advanced)
    du += (slice_end - slice_start) * ulinesize;
    dv += (slice_end - slice_start) * vlinesize;
}
