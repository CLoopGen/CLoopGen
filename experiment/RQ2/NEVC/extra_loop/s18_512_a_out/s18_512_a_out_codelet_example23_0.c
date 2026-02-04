#include <stdio.h>

extern unsigned short *a;
extern unsigned int *out;
extern int i;

void loop(){
for (i = 0; i < 512; i++)
    *out++ = *a++ << 7;

}
