#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <sys/time.h>

typedef int integer;

integer *cutpnt;
integer *indxq;
integer i__1;
integer i__;

static integer static_cutpnt;
static integer *static_indxq;
static const size_t DATA_SIZE = 64 * 1024 * 1024 / sizeof(integer); 

void init_vars() {
    struct timeval start, end;
    gettimeofday(&start, NULL);

    static_cutpnt = 1000;
    cutpnt = &static_cutpnt;

    static_indxq = (integer *)calloc(DATA_SIZE, sizeof(integer));
    if (!static_indxq) {
        exit(1);
    }
    indxq = static_indxq;

    i__1 = static_cutpnt + 50000;

    if (i__1 >= (integer)DATA_SIZE) {
        i__1 = (integer)DATA_SIZE - 1;
    }

    while (1) {
        for (i__ = *cutpnt + 1; i__ <= i__1; ++i__) {
            indxq[i__] += *cutpnt;
        }
        gettimeofday(&end, NULL);
        long elapsed = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec);
        if (elapsed >= 10000) break;
    }
}