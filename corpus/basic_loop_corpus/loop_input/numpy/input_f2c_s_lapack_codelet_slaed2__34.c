#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;

integer j;
integer *coltyp;
integer ctot[4];

void init_vars() {
    coltyp = (integer*)aligned_alloc(32, 5 * sizeof(integer));
    if (!coltyp) {
        exit(1);
    }
    for (int i = 0; i < 5; ++i) {
        coltyp[i] = 0;
    }
    for (int i = 0; i < 4; ++i) {
        ctot[i] = i + 100;
    }
}