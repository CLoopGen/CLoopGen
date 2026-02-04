#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <stdint.h>

typedef int_fast32_t jpc_fix_t;
typedef int_fast64_t jpc_fix_big_t;

int numcols;
jpc_fix_t *lptr2;
jpc_fix_t *hptr2;
int i;

#define DATA_SIZE_MB 64
#define ELEMENTS_PER_MB ((1 << 20) / sizeof(jpc_fix_t))
#define TOTAL_ELEMENTS (DATA_SIZE_MB * ELEMENTS_PER_MB)

static jpc_fix_t lptr2_data[TOTAL_ELEMENTS];
static jpc_fix_t hptr2_data[TOTAL_ELEMENTS];

void init_vars() {
    numcols = TOTAL_ELEMENTS;

    lptr2 = lptr2_data;
    hptr2 = hptr2_data;

    for (int idx = 0; idx < TOTAL_ELEMENTS; ++idx) {
        lptr2_data[idx] = (jpc_fix_t)(idx % 1000);
        hptr2_data[idx] = (jpc_fix_t)((idx + 500) % 1000);
    }

    i = 0;
}