#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

char *a;
char *b;
int len;
int diff;

static char *internal_a;
static char *internal_b;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; 
    len = (int)data_size;
    internal_a = (char *)malloc(data_size);
    internal_b = (char *)malloc(data_size);
    
    if (!internal_a || !internal_b) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    a = internal_a;
    b = internal_b;

    for (size_t i = 0; i < data_size; i++) {
        internal_a[i] = (char)(i & 0xFF);
        internal_b[i] = (char)((i + 1) & 0xFF);
    }

    diff = 0;
}