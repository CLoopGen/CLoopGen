#include <stdio.h>

#include <inttypes.h>

extern  unsigned short *a;
extern unsigned short *b;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < ((6 + 3) - 1) / 2; i++) {
        unsigned short temp1 = *(a + i);
        unsigned short temp2 = *(a + i + 1);
        *(b + 2*i) = temp1;
        *(b + 2*i + 1) = temp2;
    }
}
