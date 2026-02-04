#include <stdio.h>

#include <inttypes.h>

extern unsigned char *cont;
extern unsigned long utmp;
extern unsigned long sign;
extern int clen;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (clen > 0) {
    for (i = clen - 1; i >= 0; i--) {
        for (int j = 0; j < 1; j++) {
            cont[i] = (unsigned char)(utmp ^ sign);
            utmp >>= 8;
        }
    }
}
}
