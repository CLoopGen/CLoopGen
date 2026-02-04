#include <stdio.h>

typedef int INT_TYPE;

extern INT_TYPE *key_buff_ptr_global;
extern INT_TYPE key_array[8388608];
extern INT_TYPE key_buff2[8388608];
extern INT_TYPE i;



void loop(){
    for (INT_TYPE j = 0; j < (1 << 11); j++)
        for (i = 0; i < (1 << 12); i++)
            key_array[--key_buff_ptr_global[key_buff2[(j << 12) + i]]] = key_buff2[(j << 12) + i];
}
