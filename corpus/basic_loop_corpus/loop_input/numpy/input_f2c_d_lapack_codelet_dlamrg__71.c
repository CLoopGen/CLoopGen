#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;

integer *dtrd2;
integer *_usr_index;
integer i__1;
integer i__;
integer ind2;
integer n1sv;

#define index _usr_index

void init_vars() {
    i__1 = 10000000;  

    dtrd2 = (integer*)malloc(sizeof(integer));
    *dtrd2 = 3;

    _usr_index = (integer*)calloc(i__1, sizeof(integer));

    i__ = 0;

    ind2 = 100;
}