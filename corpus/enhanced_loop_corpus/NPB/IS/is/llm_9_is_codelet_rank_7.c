#include <stdio.h>

typedef int INT_TYPE;

extern INT_TYPE key_array[8388608];
extern INT_TYPE partial_verify_vals[5];
extern INT_TYPE test_index_array[5];
extern INT_TYPE i;



void loop(){
    for (i = 0; i < 10; i += 2) {
        INT_TYPE base_idx = test_index_array[i / 2];
        partial_verify_vals[i / 2] = (key_array[base_idx] * 3) / 2;
    }
}
