#include <stdio.h>

typedef int INT_TYPE;

extern INT_TYPE key_array[8388608];
extern INT_TYPE i;
extern INT_TYPE j;



void loop(){
INT_TYPE temp = 0;
for (i = 1; i < (1 << 23); i++) {
    temp += (key_array[i - 1] > key_array[i]);
}
j += temp;
}
