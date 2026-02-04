#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *cont;
extern int len;
extern int i;
extern unsigned long utmp;
extern unsigned long sign;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    utmp = 0;
    for (i = 0; i < len && i < 8; i++) {
        unsigned char byte = cont[i] ^ sign;
        if (byte == 0 && i > 0) {
            continue;
        }
        utmp <<= 8;
        utmp |= byte;
    }
}
