#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *EM;
extern int i;
extern int maskedDBLen;
extern unsigned char *DB;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int outer = maskedDBLen > 0 ? 1 : 0;
    int idx = 0;
    for (i = 0; i < outer; i++) {
        for (int k = 0; k < maskedDBLen; k++) {
            DB[idx] ^= EM[idx];
            idx++;
        }
    }
}
