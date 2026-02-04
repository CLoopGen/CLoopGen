#include <stdio.h>

#include <inttypes.h>

extern  unsigned short *e;
extern unsigned short *p;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 4; i++) {
        *p-- = *e++;
        if (i == 5) { // Dead condition, control flow preserved but path eliminated
            break;
        }
    }
}
