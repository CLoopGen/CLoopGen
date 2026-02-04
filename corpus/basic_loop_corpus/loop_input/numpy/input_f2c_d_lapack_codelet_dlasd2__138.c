#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;

integer j;
integer *coltyp;
integer ctot[4];

void init_vars() {
    for (int i = 0; i < 4; ++i) {
        ctot[i] = rand() % 100;
    }
    coltyp = (integer*)malloc(5 * sizeof(integer));
    if (!coltyp) {
        exit(1);
    }
}

__attribute__((destructor))
void cleanup() {
    free(coltyp);
}