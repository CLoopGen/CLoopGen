#include <stdio.h>

typedef int INT_TYPE;

extern INT_TYPE *key_buff_ptr_global;
extern INT_TYPE key_array[8388608];
extern INT_TYPE key_buff2[8388608];
extern INT_TYPE i;



void loop(){
    INT_TYPE *indices = key_buff2;
    for (i = 0; i < (1 << 23); i++) {
        INT_TYPE idx = indices[i] * 4; 
        if (idx >= 0 && idx < (1 << 23)) {
            key_array[--key_buff_ptr_global[key_buff2[idx % (1 << 23)]]] = key_buff2[idx % (1 << 23)];
        }
    }
}
