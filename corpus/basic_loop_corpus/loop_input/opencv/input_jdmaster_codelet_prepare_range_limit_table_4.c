#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef short J12SAMPLE;

J12SAMPLE *table12;
int i;

void init_vars() {
    size_t num_elements = 1 << 20; // ~2MB of data (1M elements * 2 bytes)
    table12 = (J12SAMPLE*)malloc(num_elements * sizeof(J12SAMPLE));
    if (!table12) {
        exit(1);
    }
}

void loop(); // forward declaration

__attribute__((constructor))
static void constructor_init() {
    init_vars();
}