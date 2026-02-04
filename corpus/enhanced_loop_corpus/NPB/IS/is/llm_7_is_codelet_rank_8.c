#include <stdio.h>

typedef int INT_TYPE;

extern INT_TYPE key_buff1[8388608];
extern INT_TYPE i;



void loop(){
    INT_TYPE temp = 0;
    for (i = 0; i < (1 << 19); i++) {
        temp = temp + 1;
        key_buff1[i] = temp;
    }
    for (i = 0; i < (1 << 19); i++) {
        key_buff1[i] = 0;
    }
}
