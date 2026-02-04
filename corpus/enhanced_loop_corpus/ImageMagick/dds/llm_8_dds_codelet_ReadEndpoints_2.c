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
    size_t limit = num_subsets * 2;
    for (i = 0; i < limit; i += 2) {
        unsigned char shift_c = (8 - color_bits);
        unsigned char shift_a = (8 - alpha_bits);
        unsigned char r_val, g_val, b_val, a_val;

        if (i + 1 < limit) {
            // Unroll loop by 2: process two elements per iteration
            r_val = endpoints->r[i] << shift_c;
            endpoints->r[i] = r_val | (r_val >> color_bits);

            g_val = endpoints->g[i] << shift_c;
            endpoints->g[i] = g_val | (g_val >> color_bits);

            b_val = endpoints->b[i] << shift_c;
            endpoints->b[i] = b_val | (b_val >> color_bits);

            a_val = endpoints->a[i] << shift_a;
            endpoints->a[i] = a_val | (a_val >> alpha_bits);

            r_val = endpoints->r[i+1] << shift_c;
            endpoints->r[i+1] = r_val | (r_val >> color_bits);

            g_val = endpoints->g[i+1] << shift_c;
            endpoints->g[i+1] = g_val | (g_val >> color_bits);

            b_val = endpoints->b[i+1] << shift_c;
            endpoints->b[i+1] = b_val | (b_val >> color_bits);

            a_val = endpoints->a[i+1] << shift_a;
            endpoints->a[i+1] = a_val | (a_val >> alpha_bits);
        } else {
            // Handle odd-sized case
            endpoints->r[i] <<= shift_c;
            endpoints->g[i] <<= shift_c;
            endpoints->b[i] <<= shift_c;
            endpoints->a[i] <<= shift_a;

            endpoints->r[i] |= (endpoints->r[i] >> color_bits);
            endpoints->g[i] |= (endpoints->g[i] >> color_bits);
            endpoints->b[i] |= (endpoints->b[i] >> color_bits);
            endpoints->a[i] |= (endpoints->a[i] >> alpha_bits);
        }
    }
}
