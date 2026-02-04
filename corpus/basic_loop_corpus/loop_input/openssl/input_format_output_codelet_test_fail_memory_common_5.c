#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

unsigned char *m1;
unsigned char *m2;
char *p;
size_t i;
unsigned int diff;
size_t j;

#define DATA_SIZE (512 * 1024)

static unsigned char buffer_m1[DATA_SIZE];
static unsigned char buffer_m2[DATA_SIZE];
static char output_buffer[DATA_SIZE * 2 + (DATA_SIZE / 8)];

void init_vars() {
    m1 = buffer_m1;
    m2 = buffer_m2;
    p = output_buffer;
    i = 0;
    diff = 0;
    j = DATA_SIZE;

    for (size_t idx = 0; idx < DATA_SIZE; idx++) {
        m1[idx] = (unsigned char)(idx & 0xFF);
        m2[idx] = (unsigned char)((idx + 1) & 0xFF);
    }
}