#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int argc = 1000000;
ssize_t i;
size_t *image_marker;

void init_vars() {
    image_marker = (size_t*)malloc((argc + 1) * sizeof(size_t));
    if (!image_marker) {
        exit(1);
    }
}