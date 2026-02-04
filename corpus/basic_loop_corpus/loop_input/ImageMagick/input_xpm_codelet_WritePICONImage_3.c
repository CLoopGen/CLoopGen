#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t characters_per_pixel = 0;
size_t colors = 92 * 92 * 92; 
ssize_t k;

void init_vars() {
    k = 92;
    characters_per_pixel = 0;
}