#include <stdio.h>

#include <inttypes.h>

extern unsigned char *cont;
extern unsigned long utmp;
extern unsigned long sign;
extern int clen;
extern int i;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = clen - 1; i >= 0; i--) {
    cont[i] = (unsigned char)(utmp ^ sign);
    utmp >>= 8;
}

}
