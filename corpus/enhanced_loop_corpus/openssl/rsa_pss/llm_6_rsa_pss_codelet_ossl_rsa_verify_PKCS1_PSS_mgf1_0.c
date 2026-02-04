#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *EM;
extern int i;
extern int maskedDBLen;
extern unsigned char *DB;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned char temp;
    for (i = 0; i < maskedDBLen; i++) {
        temp = EM[i];
        DB[i] ^= temp;
    }
}
