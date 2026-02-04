#include <stdio.h>

#include <inttypes.h>

extern  unsigned short *a;
extern unsigned short *b;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 3; i++) {
        unsigned short temp1 = *(a);
        unsigned short temp2 = *(a + 1);
        *b = temp1;
        *(b + 1) = temp2;
        a += 2;
        b += 2;
    }
}
