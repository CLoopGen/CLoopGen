#include <stdio.h>

typedef int INT_TYPE;

INT_TYPE key_array[8388608];
INT_TYPE i;
INT_TYPE j;

void init_vars() {
    for (INT_TYPE idx = 0; idx < 8388608; idx++) {
        key_array[idx] = idx % 1000;
    }
    i = 0;
    j = 0;
}