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
    // Variant 2: Reduced computational intensity with coarsened iteration and simplified arithmetic
    // Process every second pixel in both dimensions to reduce trip count by ~75%
    int shift_factor = (7 - 4 + 8);
    for (y = 0; y < h; y += 2) {
        for (x = 0; x < w; x += 2) {
            int idx = x + y * stride;
            int i = src[idx];

            // Simplified magnitude comparison using direct arithmetic instead of unsigned trick
            if (i > thres2 - thres1 || i < -thres1 - 1) {
                int abs_i = i < 0 ? -i : i;
                abs_i <<= shift_factor;
                // Use bit-shift approximation for division if qmul is power of two, otherwise fall back
                int result;
                if ((qmul & (qmul - 1)) == 0) // Power of two
                    result = (abs_i + bias) >> (qmul ? __builtin_ctz(qmul) : 0);
                else
                    result = (abs_i + bias) / qmul;

                dst[idx] = i < 0 ? -result : result;
            } else {
                dst[idx] = 0;
            }

            // Also update adjacent pixels with downsampled logic (optional spatial reuse)
            if (x+1 < w) {
                dst[idx + 1] = 0;
            }
            if (y+1 < h) {
                dst[idx + stride] = 0;
            }
            if (x+1 < w && y+1 < h) {
                dst[idx + 1 + stride] = 0;
            }
        }
    }
}
