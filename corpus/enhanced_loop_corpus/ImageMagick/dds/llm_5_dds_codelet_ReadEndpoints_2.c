#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct _BC7Colors {
    unsigned char r[6];
    unsigned char g[6];
    unsigned char b[6];
    unsigned char a[6];
} BC7Colors;

extern BC7Colors *endpoints;
extern unsigned char alpha_bits;
extern unsigned char color_bits;
extern size_t num_subsets;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < num_subsets * 2; i++) {
        const size_t shift_color = 8 - color_bits;
        const size_t shift_alpha = 8 - alpha_bits;

        if (color_bits == 0 || alpha_bits == 0) continue;

        endpoints->r[i] <<= shift_color;
        endpoints->g[i] <<= shift_color;
        endpoints->b[i] <<= shift_color;
        endpoints->a[i] <<= shift_alpha;

        if (color_bits >= 8) {
            endpoints->r[i] |= endpoints->r[i];
            endpoints->g[i] |= endpoints->g[i];
            endpoints->b[i] |= endpoints->b[i];
        } else {
            endpoints->r[i] |= (endpoints->r[i] >> color_bits);
            endpoints->g[i] |= (endpoints->g[i] >> color_bits);
            endpoints->b[i] |= (endpoints->b[i] >> color_bits);
        }

        if (alpha_bits >= 8) {
            endpoints->a[i] |= endpoints->a[i];
        } else {
            endpoints->a[i] |= (endpoints->a[i] >> alpha_bits);
        }
    }
}
