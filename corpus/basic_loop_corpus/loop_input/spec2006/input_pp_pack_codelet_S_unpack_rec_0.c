#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

typedef int I32;

char *PL_bitcount;
I32 bits;

void init_vars() {
    PL_bitcount = (char*)calloc(512, sizeof(char));
}

void loop();