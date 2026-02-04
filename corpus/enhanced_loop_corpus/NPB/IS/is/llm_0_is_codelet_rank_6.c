#include <stdio.h>

typedef int INT_TYPE;

extern INT_TYPE i;
extern INT_TYPE prv_buff1[524288];



void loop(){
for (INT_TYPE outer = 0; outer < (1 << 9); outer++) {
    for (i = outer * (1 << 10); i < ((outer + 1) * (1 << 10)) && i < (1 << 19) - 1; i++) {
        prv_buff1[i + 1] += prv_buff1[i];
    }
}
}
