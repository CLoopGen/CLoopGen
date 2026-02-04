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
extern size_t num_subsets;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access using pointer arithmetic
    unsigned char *r_ptr = endpoints->r;
    unsigned char *g_ptr = endpoints->g;
    unsigned char *b_ptr = endpoints->b;
    unsigned char *a_ptr = endpoints->a;
    
    size_t count = num_subsets * 2;
    for (i = 0; i < count; i++) {
        *(r_ptr++) <<= 1;
        *(g_ptr++) <<= 1;
        *(b_ptr++) <<= 1;
        *(a_ptr++) <<= 1;
    }
}
