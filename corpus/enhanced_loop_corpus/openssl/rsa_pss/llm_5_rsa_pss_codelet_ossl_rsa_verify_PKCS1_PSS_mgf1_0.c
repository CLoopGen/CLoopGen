#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *EM;
extern int i;
extern int maskedDBLen;
extern unsigned char *DB;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < maskedDBLen; i++) {
        if ((i & 1) == 0) {
            DB[i] ^= EM[i];
        } else {
            DB[i] ^= EM[i] ^ 0xFF;
        }
    }
}
