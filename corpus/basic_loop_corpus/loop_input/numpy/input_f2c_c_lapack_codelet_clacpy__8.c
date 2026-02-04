#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;
typedef float real;

typedef struct {
    real r;
    real i;
} singlecomplex;

integer *m;
singlecomplex *a;
singlecomplex *b;
integer a_dim1;
integer b_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__4;
integer i__;
integer j;

static singlecomplex a_storage[10000];
static singlecomplex b_storage[10000];

void init_vars() {
    const int size = 100;
    m = (integer*)malloc(sizeof(integer));
    *m = size;
    a_dim1 = size;
    b_dim1 = size;
    i__1 = size;

    for (int idx = 0; idx < 10000; ++idx) {
        a_storage[idx].r = (real)(idx % 100);
        a_storage[idx].i = (real)(idx % 101);
        b_storage[idx].r = 0.0f;
        b_storage[idx].i = 0.0f;
    }

    a = a_storage;
    b = b_storage;
}