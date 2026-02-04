#include <stdio.h>

extern unsigned short *a;
extern unsigned int *res;
extern int i;

void loop(){
for (i = 0; i < 8192; i++)
    *res++ = *a++ << 7;

}
