#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <sys/time.h>

typedef int integer;

integer *coltyp;
integer i__1;
integer i__;
integer nlp2;

void init_vars() {
    struct timeval start, end;
    gettimeofday(&start, NULL);

    nlp2 = 1;
    i__1 = 64000000;
    coltyp = (integer *)calloc(i__1 + 1, sizeof(integer));
    if (!coltyp) {
        exit(1);
    }

    do {
        for (i__ = nlp2; i__ <= i__1; ++i__) {
            coltyp[i__] = 2;
        }
        gettimeofday(&end, NULL);
    } while (((end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec)) < 10000.0);

    for (i__ = nlp2; i__ <= i__1; ++i__) {
        coltyp[i__] = 0;
    }
}