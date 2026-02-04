#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int DWTELEM;

typedef short IDWTELEM;

extern DWTELEM *src;
extern int stride;
extern int bias;
extern  int w;
extern  int h;
extern  int qmul;
extern int x;
extern int y;
extern int thres1;
extern int thres2;
extern IDWTELEM *dst;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int offset, val;
    // Reverse loop order to eliminate forward loop-carried dependencies
    // Introduce RAW by reordering access relative to computation
    for (y = h - 1; y >= 0; y--) {
        for (x = w - 1; x >= 0; x--) {
            offset = x + y * stride;
            val = src[offset];
            int condition = (unsigned int)(val + thres1) > thres2;
            int sign = val >= 0 ? 1 : -1;
            int abs_val = sign * val; // Normalize to positive
            int shifted = abs_val << (7 - 4 + 8);
            int corrected_bias = bias + (qmul >> 1); // Modified bias introduces data dependency on qmul
            int quantized = (shifted + corrected_bias) / qmul;
            dst[offset] = condition ? sign * quantized : 0;
        }
    }
    // Additional pass to simulate idempotent update (WAW dependency)
    // This is safe because operation is deterministic and reversible only if needed
    for (y = 0; y < h; y += 1) {
        for (x = 0; x < w; x += 1) {
            if (dst[x + y * stride] != 0) {
                // Reapply with slight variation using combined expression (reinforces WAW)
                dst[x + y * stride] = (dst[x + y * stride] + 1) - 1; // No-op with dependency chain
            }
        }
    }
}
