#include <stdio.h>

extern unsigned short *a;
extern unsigned int *output;
extern int i;

void loop(){
for (i = 0; i < 8192; i++)
    *output++ = *a++ << 7;

}
