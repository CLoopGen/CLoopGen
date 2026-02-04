#include <stdio.h>

typedef int INT_TYPE;

extern INT_TYPE i;
extern INT_TYPE prv_buff1[524288];



void loop(){
    INT_TYPE temp = 0;
    for (i = 0; i < (1 << 19); i++) {
        temp += prv_buff1[i];
        prv_buff1[i] = 0;
    }
    // Introduces a WAW and RAW dependency via 'temp', though final use is dead
    // Loop-carried dependency on 'temp' across iterations
}
