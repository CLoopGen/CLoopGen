#include <stdio.h>

typedef int INT_TYPE;

extern INT_TYPE key_array[8388608];
extern INT_TYPE i;
extern INT_TYPE j;



void loop(){
for (i = 1; i < (1 << 20); i++) {
    INT_TYPE diff = key_array[i] - key_array[i - 1];
    if (diff < 0)
        j++;
    if (key_array[i] > key_array[i - 1])
        j--;
}
}
