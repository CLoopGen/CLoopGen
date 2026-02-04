#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int DWTELEM;

DWTELEM *b0;
DWTELEM *b1;
DWTELEM *b2;
int width;
int i;

static DWTELEM *b0_data;
static DWTELEM *b1_data;
static DWTELEM *b2_data;

void init_vars() {
    size_t data_size = 64 << 20; // 64 MB of data
    size_t num_elements = data_size / sizeof(DWTELEM);
    width = (int)num_elements;

    b0_data = (DWTELEM *)aligned_alloc(32, num_elements * sizeof(DWTELEM));
    b1_data = (DWTELEM *)aligned_alloc(32, num_elements * sizeof(DWTELEM));
    b2_data = (DWTELEM *)aligned_alloc(32, num_elements * sizeof(DWTELEM));

    if (!b0_data || !b1_data || !b2_data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t j = 0; j < num_elements; j++) {
        b0_data[j] = (DWTELEM)(j % 100);
        b1_data[j] = (DWTELEM)((j + 10) % 200);
        b2_data[j] = (DWTELEM)((j + 20) % 100);
    }

    b0 = b0_data;
    b1 = b1_data;
    b2 = b2_data;
}