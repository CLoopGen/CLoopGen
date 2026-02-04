#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    int pos;
    int flags;
} keyReference;

int i;
int num;
int first;
keyReference *keys;

void init_vars() {
    num = 32 * 1024 * 1024 / sizeof(keyReference);
    first = 100;
    keys = (keyReference*)calloc(num, sizeof(keyReference));
    if (!keys) {
        exit(1);
    }
}