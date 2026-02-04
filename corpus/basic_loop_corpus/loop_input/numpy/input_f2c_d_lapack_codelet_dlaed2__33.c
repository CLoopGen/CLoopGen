#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;

integer *indx;
integer *indxc;
integer *indxp;
integer *coltyp;
integer i__1;
integer j;
integer ct;
integer js;
integer psm[4];

void init_vars() {
    i__1 = 65536;

    indxp = (integer*)calloc(i__1 + 1, sizeof(integer));
    coltyp = (integer*)calloc(i__1 + 1, sizeof(integer));
    indx = (integer*)calloc(i__1 + 1, sizeof(integer));
    indxc = (integer*)calloc(i__1 + 1, sizeof(integer));

    for (j = 1; j <= i__1; ++j) {
        indxp[j] = j;
        coltyp[j] = (j % 4) + 1;
    }

    psm[0] = 1;
    psm[1] = i__1 / 4 + 1;
    psm[2] = i__1 / 2 + 1;
    psm[3] = i__1 * 3 / 4 + 1;
}