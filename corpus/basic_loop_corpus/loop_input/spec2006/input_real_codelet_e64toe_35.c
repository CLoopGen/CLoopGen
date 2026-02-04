#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

static unsigned short *e_ptr;
static unsigned short *p_ptr;
static int i_val;

unsigned short *e;
unsigned short *p;
int i;

#define DATA_SIZE (1 << 20) // 1MB of data (2^18 elements for unsigned short)

static unsigned short input_array[DATA_SIZE / sizeof(unsigned short)];
static unsigned short output_array[DATA_SIZE / sizeof(unsigned short)];

void init_vars() {
    e_ptr = &input_array[0];
    p_ptr = &output_array[DATA_SIZE / sizeof(unsigned short) - 1];
    i_val = 0;

    e = e_ptr;
    p = p_ptr;
    i = i_val;
}