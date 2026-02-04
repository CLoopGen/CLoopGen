#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;

integer *strd1;
integer *_usr_index;
integer i__1;
integer i__;
integer ind1;
integer n2sv;

#define index _usr_index

static const size_t DATA_SIZE = 64 * 1024 * 1024; // ~64MB of data for sufficient runtime

void init_vars() {
    strd1 = (integer*)malloc(sizeof(integer));
    if (!strd1) exit(1);
    *strd1 = 4; 

    _usr_index = (integer*)calloc(DATA_SIZE, sizeof(integer));
    if (!_usr_index) exit(1);

    i__ = 0;
    ind1 = 100;
    i__1 = DATA_SIZE - 1;
}