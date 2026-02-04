#include <stdio.h>

#include <inttypes.h>

extern unsigned short *q;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = 0;
    for (i = 2; i < (6 + 3); i++) {
        temp += *q;  
        *q++ = temp;
    }
}
