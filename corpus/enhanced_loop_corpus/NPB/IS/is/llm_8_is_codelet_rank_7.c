#include <stdio.h>

typedef int INT_TYPE;

extern INT_TYPE key_array[8388608];
extern INT_TYPE partial_verify_vals[5];
extern INT_TYPE test_index_array[5];
extern INT_TYPE i;



void loop(){
    for (i = 0; i < 5; i++) {
        INT_TYPE idx = test_index_array[i] * 2 + 1;
        if (idx < 8388608) {
            partial_verify_vals[i] = key_array[idx] + key_array[idx - 1];
        } else {
            partial_verify_vals[i] = key_array[test_index_array[i]];
        }
    }
}
