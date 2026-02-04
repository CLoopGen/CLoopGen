#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <sys/time.h>

typedef int integer;

integer *dtrd1;
integer *_usr_index;
integer i__1;
integer i__;
integer ind1;
integer n2sv;

#define index _usr_index

static const size_t DATA_SIZE = 64 * 1024 * 1024; // ~64MB for sustained memory access

void init_vars() {
    // Allocate and initialize dtrd1 as a pointer to a single integer
    dtrd1 = (integer *)malloc(sizeof(integer));
    if (!dtrd1) exit(1);
    *dtrd1 = 7; // arbitrary step value

    // Allocate index array with sufficient size to avoid out-of-bounds
    _usr_index = (integer *)calloc(DATA_SIZE, sizeof(integer));
    if (!_usr_index) exit(1);

    // Set loop bounds based on allocated size
    i__1 = (integer)(DATA_SIZE - 1); // ensures index[i__] stays in bounds
    i__ = 0;
    ind1 = 100; // initial value for ind1
}