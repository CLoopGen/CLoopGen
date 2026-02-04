#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
int j;
unsigned int *Yo;
int oYstride;
int *last;
int *Y;
int Ystride;

static unsigned int Yo_data[1024 * 256];
static int last_data[1024 * 256];
static int Y_data[1024 * 256];

void init_vars() {
    const size_t total_elements = 1024 * 256;

    for (size_t idx = 0; idx < total_elements; idx++) {
        Yo_data[idx] = (unsigned int)(idx & 0xFFFFF);
        last_data[idx] = 0;
        Y_data[idx] = 0;
    }

    i = 0;
    j = 0;
    oYstride = 4;
    Ystride = 4;
    Yo = Yo_data;
    last = last_data;
    Y = Y_data;
}