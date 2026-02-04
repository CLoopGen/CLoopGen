#include <stdio.h>

typedef int INT_TYPE;

extern INT_TYPE key_buff1[8388608];
extern INT_TYPE i;



void loop(){
    for (i = 0; i < (1 << 19); i += 2) {
        key_buff1[i] = 0;
        if (i + 1 < (1 << 19))
            key_buff1[i + 1] = key_buff1[i];
    }
}
