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
        unsigned char r_val = endpoints->r[i];
        unsigned char g_val = endpoints->g[i];
        unsigned char b_val = endpoints->b[i];
        unsigned char a_val = endpoints->a[i];

        r_val <<= (8 - color_bits);
        g_val <<= (8 - color_bits);
        b_val <<= (8 - color_bits);
        a_val <<= (8 - alpha_bits);

        r_val |= (r_val >> color_bits);
        g_val |= (g_val >> color_bits);
        b_val |= (b_val >> color_bits);
        a_val |= (a_val >> alpha_bits);

        endpoints->r[i] = r_val;
        endpoints->g[i] = g_val;
        endpoints->b[i] = b_val;
        endpoints->a[i] = a_val;
    }
}
