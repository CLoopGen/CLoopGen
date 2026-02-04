#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int maskedDBLen;
extern unsigned char *DB;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int limit = maskedDBLen - 1;
    int found = 0;
    for (i = 0; i < limit && !found; i++) {
        if (DB[i] != 0)
            found = 1;
    }
    if (found) i--;
}
