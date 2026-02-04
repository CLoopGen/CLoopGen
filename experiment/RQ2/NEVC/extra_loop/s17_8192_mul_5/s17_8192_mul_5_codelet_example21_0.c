#include <stdio.h>

extern int *i1;
extern int n;
extern int i;
extern int out;

void loop(){
for (i = n - 1; i >= 0; i--)
    out *= i1[i];

}
