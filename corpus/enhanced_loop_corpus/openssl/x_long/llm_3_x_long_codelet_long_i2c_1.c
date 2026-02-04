#include <stdio.h>

#include <inttypes.h>

extern unsigned char *cont;
extern unsigned long utmp;
extern unsigned long sign;
extern int clen;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access (stride of 2, wrapping around if needed)
    int stride = 2;
    int pos = (clen - 1) % stride;  // Start at offset to ensure coverage within bounds
    utmp >>= (clen - 1) * 8;
    for (i = 0; i < clen; i++) {
        int idx = (pos + i * stride) % clen;
        cont[idx] = (unsigned char)(utmp ^ sign);
        utmp >>= 8;
    }
}
