#include <stdio.h>

extern unsigned short *a;
extern unsigned int *dst;
extern int i;

void loop(){
for (i = 0; i < 16384; i++)
    *dst++ = *a++ << 7;

}
