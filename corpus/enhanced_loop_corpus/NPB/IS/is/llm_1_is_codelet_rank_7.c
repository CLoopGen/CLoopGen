#include <stdio.h>

typedef int INT_TYPE;

extern INT_TYPE key_array[8388608];
extern INT_TYPE partial_verify_vals[5];
extern INT_TYPE test_index_array[5];
extern INT_TYPE i;



void loop(){
    for (i = 0; i < 1; i++)
        for (INT_TYPE j = 0; j < 5; j++)
            partial_verify_vals[j] = key_array[test_index_array[j]];
}
