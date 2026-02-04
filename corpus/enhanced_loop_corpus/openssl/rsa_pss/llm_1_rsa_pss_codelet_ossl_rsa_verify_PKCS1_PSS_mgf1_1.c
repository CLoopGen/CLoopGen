#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int maskedDBLen;
extern unsigned char *DB;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < (maskedDBLen - 1); ) {
        for (int inner = 0; inner < 1; inner++) {
            if (DB[i] != 0) {
                goto exit_loop;
            }
            i++;
        }
    }
exit_loop:;
}
