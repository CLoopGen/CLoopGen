#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

typedef int_fast32_t jpc_fix_t;
typedef int_fast64_t jpc_fix_big_t;

int numcols;
jpc_fix_t *lptr2;
jpc_fix_t *hptr2;
int i;

#define DATA_SIZE_MB 64
#define TOTAL_ELEMENTS ((DATA_SIZE_MB * 1024 * 1024) / sizeof(jpc_fix_t))

static jpc_fix_t lptr2_buffer[TOTAL_ELEMENTS];
static jpc_fix_t hptr2_buffer[TOTAL_ELEMENTS];

void init_vars() {
    numcols = TOTAL_ELEMENTS - 1; 

    lptr2 = lptr2_buffer;
    hptr2 = hptr2_buffer;

    for (int idx = 0; idx < TOTAL_ELEMENTS; ++idx) {
        lptr2_buffer[idx] = (jpc_fix_t)(idx & 0x7FFF);
        hptr2_buffer[idx] = (jpc_fix_t)((idx + 1) & 0x7FFF);
    }

    i = 0;
}