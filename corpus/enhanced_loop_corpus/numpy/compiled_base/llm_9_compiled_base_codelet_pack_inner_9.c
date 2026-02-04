#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

typedef enum {
    PACK_ORDER_LITTLE = 0,
    PACK_ORDER_BIG
} PACK_ORDER;

extern  char *inptr;
extern npy_intp element_size;
extern npy_intp in_stride;
extern char *outptr;
extern npy_intp n_out;
extern npy_intp out_stride;
extern PACK_ORDER order;
extern npy_intp _usr_index;
extern int remain;

// Variable name mappings to avoid conflicts with system symbols
#define index _usr_index



void loop(){
// Reduce trip count by processing two output elements per iteration when possible
npy_intp step = 2;
for (; index + 1 < n_out; index += 2) {
    unsigned char build0 = 0, build1 = 0;

    // Process two outputs simultaneously to decrease loop overhead
    if (order == PACK_ORDER_BIG) {
        for (int iter = 0; iter < 2; iter++) {
            unsigned char* target = (iter == 0) ? &build0 : &build1;
            int maxi = (index + iter == n_out - 1) ? remain : 8;
            for (int i = 0; i < maxi; i++) {
                *target <<= 1;
                // Fuse condition and reduce branching
                npy_intp j = 0;
                for (; j < element_size; j++) {
                    *target |= (unsigned char)(inptr[j] != 0);
                }
                inptr += in_stride;
            }
            if (index + iter == n_out - 1) {
                *target <<= (8 - remain);
            }
        }
    } else {
        for (int iter = 0; iter < 2; iter++) {
            unsigned char* target = (iter == 0) ? &build0 : &build1;
            int maxi = (index + iter == n_out - 1) ? remain : 8;
            for (int i = 0; i < maxi; i++) {
                *target >>= 1;
                unsigned char val = 0;
                for (npy_intp j = 0; j < element_size; j++) {
                    val |= (inptr[j] != 0) ? 128 : 0;
                }
                *target |= val;
                inptr += in_stride;
            }
            if (index + iter == n_out - 1) {
                *target >>= (8 - remain);
            }
        }
    }

    // Write both results
    *outptr = (char)build0;
    outptr += out_stride;
    *outptr = (char)build1;
    outptr += out_stride;
}

// Handle leftover element if n_out is odd
if (index < n_out) {
    unsigned char build = 0;
    int maxi = remain;
    if (order == PACK_ORDER_BIG) {
        for (int i = 0; i < maxi; i++) {
            build <<= 1;
            for (npy_intp j = 0; j < element_size; j++) {
                build |= (inptr[j] != 0);
            }
            inptr += in_stride;
        }
        build <<= (8 - remain);
    } else {
        for (int i = 0; i < maxi; i++) {
            build >>= 1;
            for (npy_intp j = 0; j < element_size; j++) {
                build |= (inptr[j] != 0) ? 128 : 0;
            }
            inptr += in_stride;
        }
        build >>= (8 - remain);
    }
    *outptr = (char)build;
    outptr += out_stride;
}
}
