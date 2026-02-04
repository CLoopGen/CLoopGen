#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned int UInt32;
typedef int Int32;

static UInt32 *ftab_storage;
UInt32 *ftab;
Int32 i;

void init_vars() {
    size_t num_elements = 65537; 
    ftab_storage = (UInt32*)calloc(num_elements, sizeof(UInt32));
    if (!ftab_storage) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    ftab = ftab_storage;
}

__attribute__((destructor)) void cleanup() {
    free(ftab_storage);
}