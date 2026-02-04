#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

extern int i;
extern npy_intp in_tail;
extern npy_intp out_stride;
extern  unsigned char *inptr;
extern char *outptr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char temp_buffer[64]; // Local buffer for consecutive memory access
    char* local_out = temp_buffer;
    for (i = 0; i < in_tail && i < 64; i++) {
        local_out[i] = ((*inptr & (1 << i)) != 0); // Write consecutively to temporary buffer
    }
    // Flush buffer to actual output with strided pattern
    for (i = 0; i < in_tail && i < 64; i++) {
        *outptr = temp_buffer[i];
        outptr += out_stride;
    }
}
