#include <stdlib.h>
#include <stddef.h>

typedef int integer;

integer *iwork;
integer i__1;
integer j;

void init_vars() {
    i__1 = 262144; // Size to achieve ~0.01 sec runtime (approx 1MB of data for int)
    iwork = (integer*)calloc(i__1 + 1, sizeof(integer));
    if (!iwork) exit(1);
}