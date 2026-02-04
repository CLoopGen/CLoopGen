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
    if (num_subsets > 0) {
        unsigned char prev_r = endpoints->r[0];
        unsigned char prev_g = endpoints->g[0];
        unsigned char prev_b = endpoints->b[0];
        unsigned char prev_a = endpoints->a[0];

        prev_r <<= (8 - color_bits);
        prev_g <<= (8 - color_bits);
        prev_b <<= (8 - color_bits);
        prev_a <<= (8 - alpha_bits);

        prev_r |= (prev_r >> color_bits);
        prev_g |= (prev_g >> color_bits);
        prev_b |= (prev_b >> color_bits);
        prev_a |= (prev_a >> alpha_bits);

        endpoints->r[0] = prev_r;
        endpoints->g[0] = prev_g;
        endpoints->b[0] = prev_b;
        endpoints->a[0] = prev_a;

        for (i = 1; i < num_subsets * 2; i++) {
            unsigned char curr_r = endpoints->r[i];
            unsigned char curr_g = endpoints->g[i];
            unsigned char curr_b = endpoints->b[i];
            unsigned char curr_a = endpoints->a[i];

            curr_r <<= (8 - color_bits);
            curr_g <<= (8 - color_bits);
            curr_b <<= (8 - color_bits);
            curr_a <<= (8 - alpha_bits);

            curr_r |= (curr_r >> color_bits);
            curr_g |= (curr_g >> color_bits);
            curr_b |= (curr_b >> color_bits);
            curr_a |= (curr_a >> alpha_bits);

            endpoints->r[i] = curr_r ^ prev_r;
            endpoints->g[i] = curr_g ^ prev_g;
            endpoints->b[i] = curr_b ^ prev_b;
            endpoints->a[i] = curr_a ^ prev_a;

            prev_r = curr_r;
            prev_g = curr_g;
            prev_b = curr_b;
            prev_a = curr_a;
        }
    }
}
