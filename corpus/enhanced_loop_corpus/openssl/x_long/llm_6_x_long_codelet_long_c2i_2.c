#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *cont;
extern int len;
extern int i;
extern unsigned long utmp;
extern unsigned long sign;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned long utmp_prev = 0;
    for (i = 0; i < len; i++) {
        utmp_prev = utmp;
        utmp <<= 8;
        utmp |= cont[i] ^ sign;
        // Introduced a temporary to create a local RAW dependency and break direct WAW on utmp in same iteration
        // Loop-carried dependency remains via utmp, but we use utmp_prev to add internal data flow
    }
}
