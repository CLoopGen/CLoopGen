#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef long JLONG;

int i;
JLONG *bptr;

static JLONG *bptr_storage;
static size_t total_elements = 1 << 25; // ~128MB of data (assuming JLONG is 8 bytes)

void init_vars() {
    bptr_storage = (JLONG*)calloc(total_elements, sizeof(JLONG));
    if (!bptr_storage) {
        exit(1);
    }
    bptr = bptr_storage;
}