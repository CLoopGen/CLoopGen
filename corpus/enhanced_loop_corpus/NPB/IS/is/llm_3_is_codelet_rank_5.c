#include <stdio.h>

typedef int INT_TYPE;

extern INT_TYPE key_array[8388608];
extern INT_TYPE key_buff2[8388608];
extern INT_TYPE i;
extern INT_TYPE prv_buff1[524288];



void loop(){
for (i = 0; i < (1 << 23); i++) {
    INT_TYPE index = (i * 3) & ((1 << 23) - 1);
    key_buff2[index] = key_array[index];
    prv_buff1[key_buff2[index]]++;
}
}
