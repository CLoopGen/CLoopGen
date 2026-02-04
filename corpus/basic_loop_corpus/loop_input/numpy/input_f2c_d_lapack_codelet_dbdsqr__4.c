#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

typedef double doublereal;
typedef int integer;

doublereal *e;
integer *info;
integer i__1;
integer i__;

static doublereal e_data[67108864]; // ~512 MB for sufficient runtime (~0.01s target)

void init_vars() {
    const size_t data_size = sizeof(e_data) / sizeof(e_data[0]);
    i__1 = (integer)(data_size - 1);
    info = (integer*)malloc(sizeof(integer));
    *info = 0;
    e = e_data;
    
    // Initialize e with mostly zeros but some non-zero to trigger condition
    for (size_t i = 0; i < data_size; ++i) {
        e[i] = (i % 7 == 0) ? (doublereal)(i * 0.001) : 0.0;
    }
}