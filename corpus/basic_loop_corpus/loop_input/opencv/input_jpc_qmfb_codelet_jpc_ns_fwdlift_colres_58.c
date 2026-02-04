#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int_fast32_t jpc_fix_t;
typedef int_fast64_t jpc_fix_big_t;

int numcols;
int stride;
jpc_fix_t *lptr2;
jpc_fix_t *hptr2;
int i;

static jpc_fix_t *lptr2_data;
static jpc_fix_t *hptr2_data;

void loop(void);

void init_vars() {
    // Aim for approximately 64M elements to achieve ~0.01s runtime on modern CPU
    size_t data_size = (1 << 26); // ~67M elements

    lptr2_data = (jpc_fix_t*)aligned_alloc(32, data_size * sizeof(jpc_fix_t));
    hptr2_data = (jpc_fix_t*)aligned_alloc(32, (data_size + data_size/4) * sizeof(jpc_fix_t));

    if (!lptr2_data || !hptr2_data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize data
    for (size_t idx = 0; idx < data_size; ++idx) {
        lptr2_data[idx] = (jpc_fix_t)(idx & 0xFFFFF);
    }
    for (size_t idx = 0; idx < data_size + data_size/4; ++idx) {
        hptr2_data[idx] = (jpc_fix_t)((idx * 7) & 0xFFFFF);
    }

    // Set parameters
    numcols = (int)data_size;
    stride = (int)(data_size / 8) + 1;  // Ensure valid access: hptr2[stride] within bounds

    // Initialize pointers
    lptr2 = lptr2_data;
    hptr2 = hptr2_data;
}