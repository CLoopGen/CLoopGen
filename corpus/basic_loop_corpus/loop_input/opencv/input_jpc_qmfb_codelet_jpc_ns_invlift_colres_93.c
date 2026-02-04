#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int_fast32_t jpc_fix_t;
typedef int_fast64_t jpc_fix_big_t;

int numcols;
jpc_fix_t *lptr2;
jpc_fix_t *hptr2;
int i;

static jpc_fix_t *lptr2_buffer;
static jpc_fix_t *hptr2_buffer;

void init_vars() {
    const size_t data_size = 1 << 20; // ~8MB total (two arrays of int_fast32_t)
    numcols = data_size;
    
    lptr2_buffer = aligned_alloc(32, data_size * sizeof(jpc_fix_t));
    hptr2_buffer = aligned_alloc(32, data_size * sizeof(jpc_fix_t));
    
    if (!lptr2_buffer || !hptr2_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
    
    for (size_t idx = 0; idx < data_size; ++idx) {
        lptr2_buffer[idx] = (jpc_fix_t)(idx & 0xFFFFF);
        hptr2_buffer[idx] = (jpc_fix_t)((idx << 5) & 0xFFFFF);
    }
    
    lptr2 = lptr2_buffer;
    hptr2 = hptr2_buffer;
}