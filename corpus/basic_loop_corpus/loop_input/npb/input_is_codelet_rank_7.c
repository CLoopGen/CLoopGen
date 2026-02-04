#include <stdio.h>

typedef int INT_TYPE;

INT_TYPE key_array[8388608];
INT_TYPE partial_verify_vals[5];
INT_TYPE test_index_array[5];
INT_TYPE i;

void init_vars() {
    for (INT_TYPE idx = 0; idx < 8388608; idx++) {
        key_array[idx] = idx * 3 + 1;
    }
    test_index_array[0] = 1000000;
    test_index_array[1] = 2000000;
    test_index_array[2] = 3000000;
    test_index_array[3] = 4000000;
    test_index_array[4] = 5000000;
    for (INT_TYPE idx = 0; idx < 5; idx++) {
        partial_verify_vals[idx] = 0;
    }
    i = 0;
}