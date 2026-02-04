#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    int pos;
    int flags;
} keyReference;

int argc = 10000000;
int i;
int num = 5000000;
keyReference *keys;
int streams_pos = 1000000;

void init_vars() {
    keys = (keyReference*)calloc(argc - num - streams_pos - 1, sizeof(keyReference));
    if (!keys) {
        exit(1);
    }
}