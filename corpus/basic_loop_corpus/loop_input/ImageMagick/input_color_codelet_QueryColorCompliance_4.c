#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

char colorspace[8192];
ssize_t j;

void init_vars() {
    for (size_t i = 0; i < sizeof(colorspace) - 1; i++) {
        colorspace[i] = 'a' + (i % 26);
    }
    colorspace[sizeof(colorspace) - 1] = '\x00';

    ssize_t break_index = rand() % (sizeof(colorspace) - 1);
    if (break_index > 0) {
        if (rand() % 2)
            colorspace[break_index] = ' ';
        else
            colorspace[break_index] = ',';
    }

    j = 0;
}