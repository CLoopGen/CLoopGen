#include <stdio.h>

typedef int INT_TYPE;

extern INT_TYPE key_array[8388608];
extern INT_TYPE partial_verify_vals[5];
extern INT_TYPE test_index_array[5];
extern INT_TYPE i;



void loop(){
    INT_TYPE accumulator = 0;
    for (i = 0; i < 5; i++) {
        accumulator += key_array[test_index_array[i]];
        partial_verify_vals[i] = accumulator;
    }
}
