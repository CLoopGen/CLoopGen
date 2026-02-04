#include <stdio.h>
#include <inttypes.h>

typedef int int32;
typedef int32 tsize_t;
typedef unsigned short uint16;

tsize_t stride;
uint16 *wp;
int i;

static uint16 *wp_storage;
static tsize_t data_size;

void init_vars() {
    data_size = 64 * 1024 * 1024; // ~128 MB of uint16 data (each uint16 is 2 bytes)
    wp_storage = (uint16*)__builtin_malloc(data_size * sizeof(uint16));
    
    for (tsize_t idx = 0; idx < data_size; idx++) {
        wp_storage[idx] = (uint16)(idx & 0xFFFF);
    }

    stride = 1024; 
    wp = wp_storage + 4; // Ensure wp[stride] access is valid: need at least stride+1 elements from base
}