#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

typedef unsigned char DES_cblock[8];

char *str;
DES_cblock *key;
int i;
size_t length;

void init_vars() {
    length = 512 * 1024; // 512 KB data size for ~0.01 sec runtime

    str = (char *)malloc(length);
    if (!str) {
        exit(1);
    }

    for (size_t idx = 0; idx < length; ++idx) {
        str[idx] = (char)(idx & 0xFF);
    }

    key = (DES_cblock *)malloc(sizeof(DES_cblock));
    if (!key) {
        free(str);
        exit(1);
    }

    memset((*key), 0, 8);
}