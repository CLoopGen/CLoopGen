#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

size_t inlen;
size_t i;
int result;
unsigned char *add;
unsigned char carry;
unsigned char *d;

#define DATA_SIZE (262144)  // 256KB, tuned for ~0.01 sec runtime

static unsigned char *d_storage;
static unsigned char *add_storage;

void init_vars() {
    d_storage = aligned_alloc(32, DATA_SIZE);
    add_storage = aligned_alloc(32, DATA_SIZE);

    if (!d_storage || !add_storage) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    memset(d_storage, 0, DATA_SIZE);
    for (size_t j = 0; j < DATA_SIZE; j++) {
        add_storage[j] = (unsigned char)(j & 0xFF);
    }

    inlen = DATA_SIZE - 1;
    i = inlen;
    d = d_storage + inlen;
    add = add_storage + inlen;
    carry = 1;
    result = 0;
}