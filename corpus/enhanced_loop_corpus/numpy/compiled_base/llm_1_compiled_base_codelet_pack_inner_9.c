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
for (; index < n_out; index++) {
    unsigned char build = 0;
    int maxi = (index == n_out - 1) ? remain : 8;
    if (order == PACK_ORDER_BIG) {
        for (int i = 0; i < maxi; i++) {
            build <<= 1;
            for (npy_intp j = 0; j < element_size; j += 2) {
                if (j + 1 < element_size) {
                    build |= (inptr[j] != 0) | (inptr[j+1] != 0);
                } else {
                    build |= (inptr[j] != 0);
                }
            }
            inptr += in_stride;
        }
        if (index == n_out - 1) {
            build <<= 8 - remain;
        }
    } else {
        for (int i = 0; i < maxi; i++) {
            build >>= 1;
            for (npy_intp j = 0; j < element_size; j += 2) {
                if (j + 1 < element_size) {
                    build |= ((inptr[j] != 0) || (inptr[j+1] != 0)) ? 128 : 0;
                } else {
                    build |= (inptr[j] != 0) ? 128 : 0;
                }
            }
            inptr += in_stride;
        }
        if (index == n_out - 1) {
            build >>= 8 - remain;
        }
    }
    *outptr = (char)build;
    outptr += out_stride;
}
}
