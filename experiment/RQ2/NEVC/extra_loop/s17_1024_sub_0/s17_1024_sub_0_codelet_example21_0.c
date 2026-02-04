#include <stdio.h>

extern int *in_array;
extern int n;
extern int i;
extern int sub;

void loop(){
for (i = n - 1; i >= 0; i--)
    sub -= in_array[i];

}
