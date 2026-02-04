#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned int png_uint_32;
typedef size_t png_alloc_size_t;

png_uint_32 h = 2048;
png_uint_32 w = 2048;
unsigned int pd = 32;
png_alloc_size_t cb_base;
int pass;

void init_vars() {
    h = 2048;
    w = 2048;
    pd = 32;
    cb_base = 0;
    pass = 0;
}