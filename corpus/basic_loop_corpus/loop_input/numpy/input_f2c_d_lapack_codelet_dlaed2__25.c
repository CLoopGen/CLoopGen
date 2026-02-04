#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <sys/time.h>

typedef int integer;

integer *n1;
integer *indxq;
integer i__1;
integer i__;
integer n1p1;

void init_vars() {
    struct timeval start, end;
    gettimeofday(&start, NULL);

    size_t data_size = 128 * 1024 * 1024; // ~128MB of data for indxq

    n1 = (integer*)malloc(sizeof(integer));
    *n1 = 1000;

    indxq = (integer*)calloc(data_size, sizeof(integer));

    n1p1 = 1;
    i__1 = data_size - 1;

    int operations = 0;
    do {
        for (i__ = n1p1; i__ <= i__1; ++i__) {
            indxq[i__] += *n1;
            operations++;
        }
        gettimeofday(&end, NULL);
    } while (((end.tv_sec - start.tv_sec) * 1000000.0 + end.tv_usec - start.tv_usec) < 10000); // Run until at least 10ms

    if (operations == 0) {
        i__1 = n1p1; 
    }
}