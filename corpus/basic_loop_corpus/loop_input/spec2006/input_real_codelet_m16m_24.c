#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

#define DATA_SIZE (1 << 20) // 1MB of data

unsigned short *pp;
unsigned int carry;
unsigned short *ps;
unsigned int aa;
unsigned int m;
int i;

static unsigned short *ps_data;
static unsigned short *pp_data;

void init_vars() {
    ps_data = (unsigned short *)calloc(DATA_SIZE, sizeof(unsigned short));
    pp_data = (unsigned short *)calloc(DATA_SIZE, sizeof(unsigned short));

    if (!ps_data || !pp_data) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Initialize with non-zero values to ensure meaningful computation
    for (size_t idx = 0; idx < DATA_SIZE / 2; ++idx) {
        ps_data[idx] = (unsigned short)(idx & 0xFFFF);
        pp_data[idx] = (unsigned short)((idx + 1) & 0xFFFF);
    }

    // Set pointers to mid-range valid positions to allow decrements and access to neighbors
    ps = &ps_data[DATA_SIZE / 4];
    pp = &pp_data[DATA_SIZE / 4];

    // Initialize scalar variables
    aa = 12345U;
    carry = 0;
    m = 0;
    i = 0;
}