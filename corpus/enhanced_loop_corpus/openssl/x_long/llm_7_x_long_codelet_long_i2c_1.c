#include <stdio.h>

#include <inttypes.h>

extern unsigned char *cont;
extern unsigned long utmp;
extern unsigned long sign;
extern int clen;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned long local_sign = sign;
    unsigned long temp_utmp = utmp;
    for (i = clen - 1; i >= 0; i--) {
        unsigned char computed_val = (unsigned char)(temp_utmp ^ local_sign);
        cont[i] = computed_val;
        temp_utmp >>= 8;
        local_sign ^= 0x8080808080808080UL; // Introduce artificial WAW and loop-carried dependency on sign
    }
}
