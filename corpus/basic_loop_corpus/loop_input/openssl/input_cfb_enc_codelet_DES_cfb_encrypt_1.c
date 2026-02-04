#include <inttypes.h>
#include <stdlib.h>

int num;
int i;
int rem;
unsigned char *ovec;

void init_vars() {
    const size_t data_size = 1024 * 128; // 128KB of data
    ovec = (unsigned char *)aligned_alloc(32, data_size);
    
    num = 16;
    rem = 3;
    i = 0;

    for (size_t idx = 0; idx < data_size; ++idx) {
        ovec[idx] = (unsigned char)(idx & 0xFF);
    }
}

__attribute__((constructor))
static void constructor_init() {
    init_vars();
}