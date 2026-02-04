#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct _RangeInfo {
    unsigned short min;
    unsigned short max;
} RangeInfo;

RangeInfo *range_info;
unsigned short *lut;
ssize_t i;
unsigned short delta;

void init_vars() {
    size_t data_size = 128 * 1024 * 1024; // ~128MB of data for significant runtime (~0.01 sec on modern CPU)
    size_t num_elements = data_size / sizeof(unsigned short);

    lut = (unsigned short *)aligned_alloc(64, num_elements * sizeof(unsigned short));
    if (!lut) exit(1);

    range_info = (RangeInfo *)aligned_alloc(64, sizeof(RangeInfo));
    if (!range_info) exit(1);

    range_info->min = 0;
    range_info->max = (unsigned short)(num_elements - 1);
    delta = 32;
}