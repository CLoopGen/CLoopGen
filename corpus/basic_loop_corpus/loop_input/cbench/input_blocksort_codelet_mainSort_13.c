#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned int UInt32;
typedef int Int32;

UInt32 *ftab;
Int32 i;

void init_vars() {
    size_t num_elements = 65537;
    ftab = (UInt32*)calloc(num_elements, sizeof(UInt32));
    if (!ftab) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
}

__attribute__((constructor))
static void constructor_init() {
    init_vars();
}