#include <stdio.h>

extern int *input;
extern int n;
extern int i;
extern int sum;

void loop(){
for (i = n - 1; i >= 0; i--)
    sum += input[i];

}
