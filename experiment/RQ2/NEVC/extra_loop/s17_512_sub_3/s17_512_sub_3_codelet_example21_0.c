#include <stdio.h>

extern int *in_array;
extern int n;
extern int i;
extern int result;

void loop(){
for (i = n - 1; i >= 0; i--)
    result -= in_array[i];

}
