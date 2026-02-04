#include <stdio.h>

typedef int INT_TYPE;

INT_TYPE key_array[8388608];
INT_TYPE key_buff2[8388608];
INT_TYPE i;
INT_TYPE prv_buff1[524288];

void init_vars() {
    for (int j = 0; j < 8388608; j++) {
        key_array[j] = j % 524288;
    }
    for (int j = 0; j < 524288; j++) {
        prv_buff1[j] = 0;
    }
    i = 0;
}