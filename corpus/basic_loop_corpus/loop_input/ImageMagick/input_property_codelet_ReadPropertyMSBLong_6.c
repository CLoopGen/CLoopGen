#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

unsigned char **p;
size_t *length;
int c;
ssize_t i;
unsigned char buffer[4];

static unsigned char *data_ptr;
static size_t data_length;

void init_vars() {
    data_length = 1024 * 1024; // ~1MB of data to target ~0.01 sec runtime
    data_ptr = (unsigned char *)calloc(data_length, sizeof(unsigned char));
    if (!data_ptr) {
        exit(1);
    }

    // Initialize with non-zero pattern for visibility
    for (size_t idx = 0; idx < data_length; idx++) {
        data_ptr[idx] = (unsigned char)(idx & 0xFF);
    }

    // Allocate space for p and length (pointers to the actual values)
    p = (unsigned char **)malloc(sizeof(unsigned char *));
    length = (size_t *)malloc(sizeof(size_t));

    if (!p || !length) {
        exit(1);
    }

    *p = data_ptr;
    *length = data_length;

    c = 0;
    i = 0;

    // Ensure buffer is initialized
    for (int j = 0; j < 4; j++) {
        buffer[j] = 0;
    }
}