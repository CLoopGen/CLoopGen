#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

#define DATA_SIZE (128 * 1024 * 1024) // 128 MB

static unsigned short *xi_internal;
static unsigned short *xi_base;
int i;

void init_vars() {
    xi_base = (unsigned short*)calloc(DATA_SIZE, sizeof(unsigned short));
    if (!xi_base) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    xi_internal = xi_base;
    i = 0;
}

unsigned short *xi = NULL;

__attribute__((constructor))
static void setup() {
    init_vars();
    xi = xi_internal;
}

__attribute__((destructor))
static void cleanup() {
    free(xi_base);
    xi_base = NULL;
    xi = NULL;
}