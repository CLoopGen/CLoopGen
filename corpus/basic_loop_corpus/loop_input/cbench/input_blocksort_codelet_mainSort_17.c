#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

typedef unsigned int UInt32;
typedef int Int32;

UInt32 *ftab;
Int32 i;

void init_vars() {
    size_t size = 65537;
    ftab = (UInt32*)calloc(size, sizeof(UInt32));
    if (!ftab) {
        exit(1);
    }
    for (size_t idx = 0; idx < size; idx++) {
        ftab[idx] = 1;
    }
}

void loop(); 

__attribute__((constructor))
static void constructor_init() {
    init_vars();
}