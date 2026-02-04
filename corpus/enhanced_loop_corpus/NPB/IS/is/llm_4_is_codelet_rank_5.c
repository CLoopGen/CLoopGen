#include <stdio.h>

typedef int INT_TYPE;

extern INT_TYPE key_array[8388608];
extern INT_TYPE key_buff2[8388608];
extern INT_TYPE i;
extern INT_TYPE prv_buff1[524288];



void loop(){
for (i = 0; i < (1 << 23); i++) {
    if (key_array[i] >= 0) {
        key_buff2[i] = key_array[i];
        prv_buff1[key_buff2[i]]++;
    }
}
}
