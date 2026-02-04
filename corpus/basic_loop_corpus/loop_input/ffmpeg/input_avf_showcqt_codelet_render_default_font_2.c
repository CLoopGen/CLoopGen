#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

const uint8_t avpriv_vga16_font[4096] = {0};

char *str;
int x;
int u;
int v;
int mask;
uint8_t *data;
int linesize;
int width;
int height;

void init_vars() {
    width = 320;
    height = 12;
    linesize = width * 4;
    str = (char*)malloc(12 * sizeof(char));
    for (int i = 0; i < 12; i++) {
        str[i] = i % 16;
    }

    size_t data_size = (size_t)linesize * height + (height / 2) * 4 * 12;
    data = (uint8_t*)calloc(data_size, sizeof(uint8_t));
}

void loop();