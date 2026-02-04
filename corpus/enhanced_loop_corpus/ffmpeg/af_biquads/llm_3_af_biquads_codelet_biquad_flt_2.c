#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int len;
extern double b0;
extern double b1;
extern double b2;
extern double a1;
extern double a2;
extern int *clippings;
extern int disabled;
extern  float *ibuf;
extern float *obuf;
extern double i1;
extern double i2;
extern double o1;
extern double o2;
extern double wet;
extern double dry;
extern double out;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive reverse-order traversal
    // The loop now iterates from the end of the array toward the beginning,
    // accessing ibuf and obuf in reverse but maintaining logical equivalence
    // by adjusting indexing. We preserve the double-sample processing per iteration.

    for (i = len - 2; i >= 0; i--) {
        // Process second sample of the pair first (reverse order logic)
        int idx2 = i + 1;
        o1 = i1 * b2 + i2 * b1 + ibuf[idx2] * b0 + o1 * a2 + o2 * a1;
        i1 = ibuf[idx2];
        out = o1 * wet + i1 * dry;
        if (disabled) {
            obuf[idx2] = i1;
        } else if (0 && out < -1.) {
            (*clippings)++;
            obuf[idx2] = -1.;
        } else if (0 && out > 1.) {
            (*clippings)++;
            obuf[idx2] = 1.;
        } else {
            obuf[idx2] = out;
        }

        // Then process first sample of the pair
        o2 = i2 * b2 + i1 * b1 + ibuf[i] * b0 + o2 * a2 + o1 * a1;
        i2 = ibuf[i];
        out = o2 * wet + i2 * dry;
        if (disabled) {
            obuf[i] = i2;
        } else if (0 && out < -1.) {
            (*clippings)++;
            obuf[i] = -1.;
        } else if (0 && out > 1.) {
            (*clippings)++;
            obuf[i] = 1.;
        } else {
            obuf[i] = out;
        }

        // Decrement i manually since the for-loop already decrements
        i--;
    }
}
