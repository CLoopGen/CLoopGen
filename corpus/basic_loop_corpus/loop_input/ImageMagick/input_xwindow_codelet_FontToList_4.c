#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

char *font;
char *p;
unsigned int fonts;

static char font_data[1 << 20]; // 1MB of data

void init_vars() {
    size_t size = sizeof(font_data);
    for (size_t i = 0; i < size - 1; i++) {
        int r = rand() % 100;
        if (r < 3) font_data[i] = ':';
        else if (r < 6) font_data[i] = ';';
        else if (r < 9) font_data[i] = ',';
        else font_data[i] = 'A' + (r % 26);
    }
    font_data[size - 1] = '\x00';

    font = font_data;
    p = font;
    fonts = 0;
}