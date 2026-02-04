#include <stdio.h>

typedef int INT_TYPE;

INT_TYPE key_buff1[8388608];
INT_TYPE i;
INT_TYPE prv_buff1[524288];

void init_vars() {
    for (int j = 0; j < 8388608; j++) {
        key_buff1[j] = j % 65536;
    }
    for (int j = 0; j < 524288; j++) {
        prv_buff1[j] = (j + 1) * 2;
    }
    i = 0;
}