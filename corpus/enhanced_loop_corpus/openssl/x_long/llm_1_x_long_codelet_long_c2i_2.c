#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *cont;
extern int len;
extern int i;
extern unsigned long utmp;
extern unsigned long sign;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (len > 0) {
    for (i = 0; i < len; i++) {
        utmp <<= 8;
        utmp |= cont[i] ^ sign;
    }
} else {
    utmp = 0;
}
}
