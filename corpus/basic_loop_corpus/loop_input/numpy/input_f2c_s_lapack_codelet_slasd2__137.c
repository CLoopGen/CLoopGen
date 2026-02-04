#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;

integer *idxp;
integer *idxc;
integer *coltyp;
integer i__1;
integer j;
integer ct;
integer jp;
integer psm[4];

static integer idxp_data[65536];
static integer idxc_data[65536];
static integer coltyp_data[65536];

void init_vars() {
    i__1 = 65535;

    for (int i = 0; i <= i__1; ++i) {
        idxp_data[i] = rand() % 65535 + 1;
        coltyp_data[i] = rand() % 4 + 1;
    }

    for (int i = 0; i < 4; ++i) {
        psm[i] = rand() % 1000;
    }

    idxp = idxp_data;
    idxc = idxc_data;
    coltyp = coltyp_data;
}