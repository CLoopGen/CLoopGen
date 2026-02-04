#include <stdio.h>

extern unsigned short *a;
extern unsigned int *result;
extern int i;

void loop(){
for (i = 0; i < 64; i++)
    *result++ = *a++ << 7;

}
