#include <stdio.h>

typedef int INT_TYPE;

extern INT_TYPE key_array[8388608];
extern INT_TYPE i;
extern INT_TYPE j;



void loop(){
for (i = 2; i < (1 << 23); i += 2)
    if (key_array[i - 2] > key_array[i])
        j++;
}
