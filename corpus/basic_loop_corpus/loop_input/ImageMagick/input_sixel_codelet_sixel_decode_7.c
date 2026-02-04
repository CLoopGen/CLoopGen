#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

unsigned char **palette;
size_t *ncolors;
int n;
int sixel_palet[1024];

static unsigned char *palette_data;
static size_t ncolors_value;

void init_vars() {
    ncolors_value = 1024;
    ncolors = &ncolors_value;

    palette_data = (unsigned char *)calloc(1024 * 4, sizeof(unsigned char));
    if (!palette_data) exit(1);
    palette = &palette_data;

    for (int i = 0; i < 1024; ++i) {
        sixel_palet[i] = i * 0x80401;
    }
}