#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned short J16SAMPLE;

J16SAMPLE *table16;
int i;

void init_vars() {
    size_t num_elements = 65536;
    table16 = (J16SAMPLE*)malloc(num_elements * sizeof(J16SAMPLE));
    if (!table16) {
        exit(1);
    }
}

void loop();