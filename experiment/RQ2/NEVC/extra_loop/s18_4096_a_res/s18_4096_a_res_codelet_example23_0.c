#include <stdio.h>

extern unsigned short *a;
extern unsigned int *res;
extern int i;

void loop(){
for (i = 0; i < 4096; i++)
    *res++ = *a++ << 7;

}
