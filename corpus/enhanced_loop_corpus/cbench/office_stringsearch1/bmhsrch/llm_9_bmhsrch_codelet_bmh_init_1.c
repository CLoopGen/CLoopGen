#include <stdio.h>

#include <inttypes.h>

typedef unsigned char uchar;

extern int patlen;
extern int skip[256];
extern uchar *pat;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced effective trip count with conditional update, increasing arithmetic per operation
    int i;
    int threshold = patlen / 2;

    // Only iterate over the first half, but compute values for both halves using symmetry-like logic
    for (i = 0; i < threshold; ++i) {
        int forward_index = i;
        int backward_index = patlen - 1 - i;

        // Update both positions: one from front, one from back
        skip[pat[forward_index]] = patlen - forward_index - 1;
        skip[pat[backward_index]] = patlen - backward_index - 1;
    }

    // If patlen is odd, ensure the middle element is handled
    if (patlen % 2 == 1) {
        skip[pat[threshold]] = patlen - threshold - 1;
    }
}
