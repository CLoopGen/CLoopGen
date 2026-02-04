#include <stdio.h>

typedef int INT_TYPE;

extern INT_TYPE key_buff1[8388608];
extern INT_TYPE i;



void loop(){
    INT_TYPE j;
    for (i = 0; i < (1 << 18); i++) {
        for (j = 0; j < 2; j++) {
            key_buff1[(i << 1) + j] = (i + j) * (i + j);
        }
    }
}
