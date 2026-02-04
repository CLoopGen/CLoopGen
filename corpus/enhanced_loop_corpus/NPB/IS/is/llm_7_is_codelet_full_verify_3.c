#include <stdio.h>

typedef int INT_TYPE;

extern INT_TYPE key_array[8388608];
extern INT_TYPE i;
extern INT_TYPE j;



void loop(){
for (i = 1; i < (1 << 23); i += 2) {
    INT_TYPE comp1 = 0, comp2 = 0;
    if (i - 1 >= 1) {
        if (key_array[i - 2] > key_array[i - 1])
            comp1 = 1;
    }
    if (key_array[i - 1] > key_array[i])
        comp2 = 1;
    j += comp1 + comp2;
}
}
