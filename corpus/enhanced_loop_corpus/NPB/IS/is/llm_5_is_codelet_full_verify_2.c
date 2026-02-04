#include <stdio.h>

typedef int INT_TYPE;

extern INT_TYPE *key_buff_ptr_global;
extern INT_TYPE key_array[8388608];
extern INT_TYPE key_buff2[8388608];
extern INT_TYPE i;



void loop(){
    for (i = 0; i < (1 << 23); i++) {
        INT_TYPE val = key_buff2[i];
        key_buff_ptr_global[val]--;
        if ((i & 15) < 8) {
            key_array[key_buff_ptr_global[val]] = val;
        }
    }
}
