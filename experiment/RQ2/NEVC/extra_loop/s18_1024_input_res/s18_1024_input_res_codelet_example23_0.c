#include <stdio.h>

extern unsigned short *input;
extern unsigned int *res;
extern int i;

void loop(){
for (i = 0; i < 1024; i++)
    *res++ = *input++ << 7;

}
