#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int maskedDBLen;
extern unsigned char *DB;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; DB[i] == 0 && i < (maskedDBLen - 1); i++)
    ;

}
