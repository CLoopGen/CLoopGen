#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>

typedef int integer;

integer *strd2;
integer *_usr_index;
integer i__1;
integer i__;
integer ind2;
integer n1sv;

#define index _usr_index

void init_vars() {
    i__1 = 10000000; 

    strd2 = (integer*)malloc(sizeof(integer));
    *strd2 = 2;

    _usr_index = (integer*)malloc(i__1 * sizeof(integer));
    if (!_usr_index || !strd2) {
        exit(1);
    }

    i__ = 0;
    ind2 = 1;

    for (int i = 0; i < i__1; ++i) {
        _usr_index[i] = 0;
    }
}