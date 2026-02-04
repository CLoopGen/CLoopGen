#include <stdio.h>

extern int *in;
extern int n;
extern int i;
extern int mul;

void loop(){
for (i = n - 1; i >= 0; i--)
    mul *= in[i];

}
