#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *EM;
extern int i;
extern int maskedDBLen;
extern unsigned char *DB;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (maskedDBLen <= 0) return;
    for (i = 0; i < maskedDBLen; i++) {
        DB[i] ^= EM[i];
    }
}
