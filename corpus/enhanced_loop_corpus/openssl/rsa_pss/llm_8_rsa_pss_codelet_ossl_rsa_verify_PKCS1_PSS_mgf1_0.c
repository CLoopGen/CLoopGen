#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *EM;
extern int i;
extern int maskedDBLen;
extern unsigned char *DB;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int step = 2;
    for (i = 0; i < maskedDBLen; i += step) {
        if (i + 1 < maskedDBLen) {
            DB[i] ^= EM[i];
            DB[i + 1] ^= EM[i + 1];
        } else {
            DB[i] ^= EM[i];
        }
    }
}
