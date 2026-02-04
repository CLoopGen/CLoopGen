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
    // Variant 1: Consecutive memory access using pointer arithmetic
    unsigned char *r_ptr = endpoints->r;
    unsigned char *g_ptr = endpoints->g;
    unsigned char *b_ptr = endpoints->b;
    unsigned char *a_ptr = endpoints->a;
    size_t total_elements = num_subsets * 2;

    for (i = 0; i < total_elements; i++) {
        unsigned char cb_mask = 8 - color_bits;
        unsigned char ab_mask = 8 - alpha_bits;

        r_ptr[i] <<= cb_mask;
        g_ptr[i] <<= cb_mask;
        b_ptr[i] <<= cb_mask;
        a_ptr[i] <<= ab_mask;

        r_ptr[i] |= (r_ptr[i] >> color_bits);
        g_ptr[i] |= (g_ptr[i] >> color_bits);
        b_ptr[i] |= (b_ptr[i] >> color_bits);
        a_ptr[i] |= (a_ptr[i] >> alpha_bits);
    }
}
