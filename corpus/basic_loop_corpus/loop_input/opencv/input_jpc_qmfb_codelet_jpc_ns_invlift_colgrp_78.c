#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int_fast32_t jpc_fix_t;
typedef int_fast64_t jpc_fix_big_t;

jpc_fix_t *lptr2;
jpc_fix_t *hptr2;
int i;

static jpc_fix_t *lptr2_buffer;
static jpc_fix_t *hptr2_buffer;
static size_t data_size = 1 << 20; // ~8MB total data (each element is 4 bytes, two arrays)

void init_vars() {
    lptr2_buffer = (jpc_fix_t*)calloc(data_size, sizeof(jpc_fix_t));
    hptr2_buffer = (jpc_fix_t*)calloc(data_size, sizeof(jpc_fix_t));
    
    if (!lptr2_buffer || !hptr2_buffer) {
        exit(1);
    }
    
    for (size_t idx = 0; idx < data_size; ++idx) {
        lptr2_buffer[idx] = (jpc_fix_t)(idx & 0xFFFFF);
        hptr2_buffer[idx] = (jpc_fix_t)((idx + 0x5A5A5) & 0xFFFFF);
    }
    
    lptr2 = lptr2_buffer;
    hptr2 = hptr2_buffer;
}