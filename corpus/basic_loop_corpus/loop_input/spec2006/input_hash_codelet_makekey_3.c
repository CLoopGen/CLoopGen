#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char uint8;
typedef int int32;

uint8 *data;
int32 len;
char *key;
int32 i;
int32 j;

void init_vars() {
    len = 64 * 1024 * 1024;  // 64 MB, adjust for ~0.01 sec runtime on modern CPU

    data = (uint8*)malloc(len * sizeof(uint8));
    key = (char*)malloc(2 * len * sizeof(char));

    if (!data || !key) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (int32 idx = 0; idx < len; idx++) {
        data[idx] = (uint8)(idx & 0xFF);
    }

    for (int32 idx = 0; idx < 2 * len; idx++) {
        key[idx] = 0;
    }

    i = 0;
    j = 0;
}