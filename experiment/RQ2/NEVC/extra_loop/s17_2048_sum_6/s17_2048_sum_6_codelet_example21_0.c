#include <stdio.h>

extern int *in;
extern int n;
extern int i;
extern int output;

void loop(){
for (i = n - 1; i >= 0; i--)
    output += in[i];

}
