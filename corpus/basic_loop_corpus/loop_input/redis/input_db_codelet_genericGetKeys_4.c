#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    int pos;
    int flags;
} keyReference;

int firstKeyOfs = 100;
int keyStep = 4;
int i = 0;
int num = 65536;  // Size chosen to ensure ~0.01 sec runtime (approx 256KB of data)
keyReference *keys = NULL;

void init_vars() {
    keys = (keyReference*)calloc(num, sizeof(keyReference));
    if (!keys) {
        fprintf(stderr, "Failed to allocate memory for keys\n");
        exit(1);
    }
}