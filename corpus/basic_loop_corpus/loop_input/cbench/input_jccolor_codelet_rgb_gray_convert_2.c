#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

typedef long INT32;
typedef unsigned char JSAMPLE;
typedef JSAMPLE *JSAMPROW;
typedef unsigned int JDIMENSION;

int r;
int g;
int b;
INT32 *ctab;
JSAMPROW inptr;
JSAMPROW outptr;
JDIMENSION col;
JDIMENSION num_cols;

void init_vars() {
    const int input_size = 8000000; // ~24MB of input (ensures ~0.01s runtime)
    const int table_size = 3 * (256 + 1);
    
    inptr = (JSAMPROW)aligned_alloc(32, input_size);
    outptr = (JSAMPROW)aligned_alloc(32, input_size / 3);
    ctab = (INT32*)aligned_alloc(32, table_size * sizeof(INT32));
    
    num_cols = input_size / 3;
    
    for (int i = 0; i < input_size; i++) {
        inptr[i] = (JSAMPLE)(i % 256);
    }
    
    for (int i = 0; i < table_size; i++) {
        ctab[i] = (INT32)(i * 1000);
    }
    
    memset(outptr, 0, input_size / 3);
}