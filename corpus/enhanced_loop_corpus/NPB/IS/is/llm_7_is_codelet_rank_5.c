#include <stdio.h>

typedef int INT_TYPE;

extern INT_TYPE key_array[8388608];
extern INT_TYPE key_buff2[8388608];
extern INT_TYPE i;
extern INT_TYPE prv_buff1[524288];



void loop(){
INT_TYPE temp;
for (i = 0; i < (1 << 23); i++) {
    temp = key_array[i];
    key_buff2[i] = temp;
    prv_buff1[temp]++;
}
}
