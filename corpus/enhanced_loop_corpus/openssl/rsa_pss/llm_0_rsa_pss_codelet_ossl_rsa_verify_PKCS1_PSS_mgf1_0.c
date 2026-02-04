#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *EM;
extern int i;
extern int maskedDBLen;
extern unsigned char *DB;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (j = 0; j < 1; j++)
        for (i = 0; i < maskedDBLen; i++)
            DB[i] ^= EM[i];
}
