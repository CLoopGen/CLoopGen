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
    npy_intp base_in_offset = index * in_stride;
    if (order == PACK_ORDER_BIG) {
        for (int i = 0; i < maxi; i++) {
            build <<= 1;
            npy_intp current_offset = base_in_offset + i * in_stride;
            for (npy_intp j = 0; j < element_size; j++) {
                build |= (*(inptr + current_offset + j) != 0);
            }
        }
        if (index == n_out - 1) {
            build <<= 8 - remain;
        }
    } else {
        for (int i = 0; i < maxi; i++) {
            build >>= 1;
            npy_intp current_offset = base_in_offset + i * in_stride;
            for (npy_intp j = 0; j < element_size; j++) {
                build |= (*(inptr + current_offset + j) != 0) ? 128 : 0;
            }
        }
        if (index == n_out - 1) {
            build >>= 8 - remain;
        }
    }
    *(outptr + index * out_stride) = (char)build;
}
}
