#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int maskedDBLen;
extern unsigned char *DB;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_i = 0;
    for (i = 0; i < (maskedDBLen - 1); i++) {
        if (DB[temp_i] == 0) {
            temp_i++;
        } else {
            break;
        }
    }
    i = temp_i;
}
