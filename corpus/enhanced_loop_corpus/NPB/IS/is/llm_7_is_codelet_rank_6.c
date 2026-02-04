#include <stdio.h>

typedef int INT_TYPE;

extern INT_TYPE i;
extern INT_TYPE prv_buff1[524288];



void loop(){
    INT_TYPE temp = prv_buff1[0];
    for (i = 0; i < (1 << 19) - 1; i++) {
        INT_TYPE current = prv_buff1[i];
        prv_buff1[i + 1] = temp + current;
        temp = current;
    }
}
