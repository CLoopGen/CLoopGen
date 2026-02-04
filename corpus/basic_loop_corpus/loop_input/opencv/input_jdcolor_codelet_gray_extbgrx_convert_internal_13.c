#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned char JSAMPLE;
typedef JSAMPLE *JSAMPROW;
typedef unsigned int JDIMENSION;

JSAMPROW inptr;
JSAMPROW outptr;
JDIMENSION col;
JDIMENSION num_cols;

#define IN_SIZE (64 * 1024 * 1024) // ~64MB input to target ~0.01s runtime
#define OUT_SIZE (IN_SIZE * 4)

static JSAMPLE *in_buffer;
static JSAMPLE *out_buffer;

void init_vars() {
    in_buffer = (JSAMPLE*)malloc(IN_SIZE * sizeof(JSAMPLE));
    out_buffer = (JSAMPLE*)malloc(OUT_SIZE * sizeof(JSAMPLE));
    
    if (!in_buffer || !out_buffer) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    
    for (size_t i = 0; i < IN_SIZE; i++) {
        in_buffer[i] = (JSAMPLE)(i & 0xFF);
    }
    
    inptr = in_buffer;
    outptr = out_buffer;
    num_cols = IN_SIZE;
}

__attribute__((destructor))
void cleanup() {
    free(in_buffer);
    free(out_buffer);
}