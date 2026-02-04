#include <stdlib.h>
#include <stdint.h>

typedef unsigned short J16SAMPLE;

J16SAMPLE *table16;
int i;

void init_vars() {
    size_t total_size = 2 * (65535 + 1) + 1;
    table16 = (J16SAMPLE*)calloc(total_size, sizeof(J16SAMPLE));
}

void loop();