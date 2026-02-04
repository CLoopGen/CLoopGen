#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned int UInt32;
typedef int Int32;

UInt32 *ftab;
Int32 i;

void init_vars() {
    ftab = (UInt32*)calloc(65537, sizeof(UInt32));
    if (!ftab) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
}

void loop(); 

__attribute__((constructor))
static void setup() {
    init_vars();
}