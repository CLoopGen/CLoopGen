#include <stdio.h>

#include <inttypes.h>

extern unsigned char *cont;
extern unsigned long utmp;
extern unsigned long sign;
extern int clen;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int step = 2;
    for (i = clen - 1; i >= 0; i -= step) {
        cont[i] = (unsigned char)(utmp ^ sign);
        utmp >>= 8;
        if (i > 0) {
            cont[i-1] = (unsigned char)((utmp >> 4) ^ (sign << 4));
            utmp >>= 8;
        }
    }
}
