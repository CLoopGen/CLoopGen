#include <stdio.h>

typedef int INT_TYPE;

INT_TYPE key_array[8388608];
INT_TYPE key_buff2[8388608];
INT_TYPE i;

INT_TYPE temp_key_buff_ptr[8388608];

INT_TYPE *key_buff_ptr_global = temp_key_buff_ptr;

void init_vars() {
    for (int j = 0; j < 8388608; j++) {
        key_buff2[j] = (j % (8388608 - 1)) + 1;
        temp_key_buff_ptr[j] = 8388607 - j;
        key_array[j] = 0;
    }
}