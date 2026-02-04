#include <stdlib.h>
#include <stdint.h>

size_t *p;
size_t count;
size_t i;

void init_vars() {
    count = 32000000; // Approximately 256MB for size_t (8 bytes each)
    p = malloc(count * sizeof(size_t));
    if (!p) {
        exit(1);
    }
}