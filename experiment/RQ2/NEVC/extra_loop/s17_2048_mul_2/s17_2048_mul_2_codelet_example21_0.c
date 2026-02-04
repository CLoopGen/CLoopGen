#include <stdio.h>

extern int *input;
extern int n;
extern int i;
extern int mul;

void loop(){
for (i = n - 1; i >= 0; i--)
    mul *= input[i];

}
