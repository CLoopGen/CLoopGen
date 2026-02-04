#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *EM;
extern int i;
extern int maskedDBLen;
extern unsigned char *DB;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = maskedDBLen - 1; i >= 0; i--) {
        DB[i] ^= EM[i];
    }
}
