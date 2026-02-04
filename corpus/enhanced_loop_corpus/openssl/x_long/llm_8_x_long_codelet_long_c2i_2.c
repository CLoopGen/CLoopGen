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
    for (i = 0; i < len; i += 2) {
        utmp <<= 16;
        utmp |= ((cont[i] ^ sign) << 8);
        if (i + 1 < len) {
            utmp |= (cont[i + 1] ^ sign);
        }
    }
}
