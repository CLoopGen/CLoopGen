#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

ssize_t i;
unsigned char *colormap;

void init_vars() {
    colormap = (unsigned char *)calloc(768, sizeof(unsigned char));
}

void loop();