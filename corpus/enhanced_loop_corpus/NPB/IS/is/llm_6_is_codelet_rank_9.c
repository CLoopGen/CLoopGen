#include <stdio.h>

typedef int INT_TYPE;

extern INT_TYPE key_buff1[8388608];
extern INT_TYPE i;
extern INT_TYPE prv_buff1[524288];



void loop(){
    INT_TYPE temp[32];
    for (i = 0; i < (1 << 19); i++) {
        temp[i & 31] = key_buff1[i];
        key_buff1[i] = temp[i & 31] + prv_buff1[i];
    }
}
