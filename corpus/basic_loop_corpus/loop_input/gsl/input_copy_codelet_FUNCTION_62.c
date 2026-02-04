#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

size_t src_size1;
size_t i;

void init_vars() {
    src_size1 = 67108864;  // 64 million iterations ~0.01 sec on typical modern CPU
}