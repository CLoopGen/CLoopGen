#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t src_size1;
size_t i;

void init_vars() {
    src_size1 = 67108864; // Approximately 64M iterations to target ~0.01 sec on modern CPU
}