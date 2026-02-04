#include <stdio.h>

extern unsigned short *d;
extern unsigned int *result;
extern int i;

void loop(){
for (i = 0; i < 128; i++)
    *result++ = *d++ << 7;

}
