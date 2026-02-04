#include <stdio.h>

typedef int INT_TYPE;

INT_TYPE i;
INT_TYPE prv_buff1[524288];

void init_vars() {
    i = 0;
    for (int j = 0; j < 524288; j++) {
        prv_buff1[j] = 0;
    }
}