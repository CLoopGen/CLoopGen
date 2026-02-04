#include <stdio.h>

typedef int INT_TYPE;

extern INT_TYPE *key_buff_ptr_global;
extern INT_TYPE key_array[8388608];
extern INT_TYPE key_buff2[8388608];
extern INT_TYPE i;



void loop(){
    for (i = 0; i < (1 << 23); i += 2) {
        INT_TYPE val1 = key_buff2[i];
        INT_TYPE val2 = key_buff2[i + 1];
        key_array[--key_buff_ptr_global[val1]] = val1;
        key_array[--key_buff_ptr_global[val2]] = val2;
    }
}
