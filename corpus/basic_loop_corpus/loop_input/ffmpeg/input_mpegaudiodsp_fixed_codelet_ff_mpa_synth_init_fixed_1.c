#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int32_t MPA_INT;

MPA_INT *window;
int i;
int j;

void init_vars() {
    size_t total_size = 16 * 1024 * 1024; // 16 MB to ensure ~0.01 sec runtime
    window = (MPA_INT*)aligned_alloc(32, total_size * sizeof(MPA_INT));
    
    for (size_t idx = 0; idx < total_size; idx++) {
        window[idx] = (MPA_INT)(idx % 1000);
    }
}