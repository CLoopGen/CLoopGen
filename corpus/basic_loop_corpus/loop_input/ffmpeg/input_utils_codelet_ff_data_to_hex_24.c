#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

char *buff;
uint8_t *src;
int s;
int i;
char *hex_table;

void init_vars() {
    s = 64 * 1024 * 1024; // 64 million iterations -> ~128MB output, ~64MB input

    hex_table = "0123456789abcdef";

    src = (uint8_t *)malloc(s * sizeof(uint8_t));
    buff = (char *)malloc(2 * s * sizeof(char));

    for (int j = 0; j < s; j++) {
        src[j] = rand() & 0xFF;
    }

    i = 0;
}