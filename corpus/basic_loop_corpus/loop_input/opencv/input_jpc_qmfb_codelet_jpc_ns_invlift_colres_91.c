#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <stdint.h>

typedef int_fast32_t jpc_fix_t;
typedef int_fast64_t jpc_fix_big_t;

int numcols;
int stride;
jpc_fix_t *lptr2;
jpc_fix_t *hptr2;
int i;

#define DATA_SIZE_MB 64
#define TOTAL_ELEMENTS ((DATA_SIZE_MB * 1024 * 1024) / (2 * sizeof(jpc_fix_t)))

static jpc_fix_t lptr_buffer[TOTAL_ELEMENTS];
static jpc_fix_t hptr_buffer[TOTAL_ELEMENTS * 2]; // account for stride access

void init_vars() {
    numcols = TOTAL_ELEMENTS;
    stride = TOTAL_ELEMENTS / 8 + 1; // ensure valid within buffer size

    if (stride >= TOTAL_ELEMENTS) {
        stride = TOTAL_ELEMENTS / 2;
    }

    lptr2 = lptr_buffer;
    hptr2 = hptr_buffer;

    for (int idx = 0; idx < TOTAL_ELEMENTS; ++idx) {
        lptr_buffer[idx] = (jpc_fix_t)(idx & 0xFF);
    }
    for (int idx = 0; idx < TOTAL_ELEMENTS * 2; ++idx) {
        hptr_buffer[idx] = (jpc_fix_t)((idx * 7) & 0x1FF);
    }
}