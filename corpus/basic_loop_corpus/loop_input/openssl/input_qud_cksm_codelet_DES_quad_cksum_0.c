#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned int DES_LONG;

unsigned char *input;
long length;
int out_count;
DES_LONG z0;
DES_LONG z1;
DES_LONG t0;
DES_LONG t1;
int i;
long l;
unsigned char *cp;
DES_LONG *lp;

static unsigned char input_buffer[512 * 1024];
static DES_LONG lp_buffer[8];

void init_vars() {
    size_t input_size = sizeof(input_buffer);
    
    for (size_t j = 0; j < input_size; j++) {
        input_buffer[j] = (unsigned char)(j & 0xFF);
    }
    
    input = input_buffer;
    length = input_size;
    out_count = 4;
    z0 = 0x12345678;
    z1 = 0x9abcdef0;
    t0 = 0;
    t1 = 0;
    i = 0;
    l = 0;
    cp = NULL;
    lp = lp_buffer;
}