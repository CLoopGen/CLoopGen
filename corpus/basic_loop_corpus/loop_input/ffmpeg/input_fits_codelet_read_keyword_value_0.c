#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

uint8_t *ptr8;
char *keyword;
int i;

static uint8_t ptr8_buffer[262144]; // 256KB data
static char keyword_buffer[8];

void init_vars() {
    ptr8 = ptr8_buffer;
    keyword = keyword_buffer;

    for (int j = 0; j < 7; j++) {
        ptr8[j] = 'A' + (j % 26);
    }
    ptr8[7] = ' '; // Ensure loop stops at i=7

    for (int j = 0; j < 8; j++) {
        keyword[j] = 0;
    }

    i = 0;
}