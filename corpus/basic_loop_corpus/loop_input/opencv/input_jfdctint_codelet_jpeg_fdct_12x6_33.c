#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

typedef long INT32;
typedef int DCTELEM;

INT32 tmp0;
INT32 tmp1;
INT32 tmp2;
INT32 tmp10;
INT32 tmp11;
INT32 tmp12;
DCTELEM *dataptr;
int ctr;

static DCTELEM *data_buffer;
static size_t data_size;
static size_t num_elements;

void init_vars() {
    const double scale_factor = 1.7777777779999999;
    const double coeff1 = 2.1773242160000001;
    const double coeff2 = 1.2570787219999999;
    const double coeff3 = 0.65071182900000002;

    data_size = (1 << 20); 
    num_elements = data_size / sizeof(DCTELEM);

    data_buffer = (DCTELEM*)aligned_alloc(64, data_size);
    if (!data_buffer) {
        exit(1);
    }

    for (size_t i = 0; i < num_elements; i++) {
        data_buffer[i] = (DCTELEM)(i % 256 - 128);
    }

    dataptr = data_buffer;
    tmp0 = 0;
    tmp1 = 0;
    tmp2 = 0;
    tmp10 = 0;
    tmp11 = 0;
    tmp12 = 0;
    ctr = 0;
}