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
for (; index < n_out; ++index) {
    unsigned char build = 0;
    const int is_last = (index == n_out - 1);
    const int maxi = is_last ? remain : 8;

    // Merge control flow using conditional expressions and eliminate nested conditionals
    for (int i = 0; i < maxi; ++i) {
        npy_intp temp_val = 0;
        for (npy_intp j = 0; j < element_size; ++j) {
            temp_val |= inptr[j];
        }
        const unsigned char bit = (temp_val != 0) ? 1U : 0U;

        if (order == PACK_ORDER_BIG) {
            build = (unsigned char)((build << 1) | bit);
        } else {
            build = (unsigned char)((build >> 1) | (bit << 7));
        }

        inptr += in_stride;
    }

    // Apply final shift only if it's the last iteration and remain is less than 8
    if (is_last && remain < 8) {
        build = (order == PACK_ORDER_BIG) ? 
            (unsigned char)(build << (8 - remain)) : 
            (unsigned char)(build >> (8 - remain));
    }

    *outptr = (char)build;
    outptr += out_stride;
}
}
