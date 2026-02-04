#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int maskedDBLen;
extern unsigned char *DB;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int prev_i = -1;
    for (i = 0; i < (maskedDBLen - 1) && DB[i] == 0; i++) {
        prev_i = i;
    }
    if (prev_i != -1) {
        i = prev_i + 1;
    } else {
        i = 0;
    }
}
