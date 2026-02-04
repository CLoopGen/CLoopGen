#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

extern int i;
extern npy_intp in_n;
extern npy_intp in_stride;
extern npy_intp out_stride;
extern npy_intp _usr_index;
extern  unsigned char *inptr;
extern char *outptr;

// Variable name mappings to avoid conflicts with system symbols
#define index _usr_index



void loop(){
    npy_intp index;
    int i;
    // Variant 2: Indirect memory access via index array - simulate scatter write using precomputed output indices
    // Assume we have an external array of output pointers: char **out_indices (not defined here, but conceptually used)
    // For self-containment, we simulate indirect access with a fake lookup table on stack
    char **indirect_table = (char**)malloc(in_n * 8 * sizeof(char*));
    if (!indirect_table) return;

    char *base_outptr = outptr;
    for (npy_intp pos = 0; pos < in_n * 8; pos++) {
        indirect_table[pos] = base_outptr + pos * out_stride;
    }

    for (index = 0; index < in_n; index++) {
        for (i = 0; i < 8; i++) {
            npy_intp flat_idx = index * 8 + i;
            *(indirect_table[flat_idx]) = ((*inptr & (1 << i)) != 0);
        }
        inptr += in_stride;
    }

    // Update outptr as if it were advanced by last element stride (conceptual)
    outptr = indirect_table[in_n * 8 - 1] + out_stride;
    free(indirect_table);
}
