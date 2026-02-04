#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *ptr8;
extern char *keyword;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int depth1 = 0; depth1 < 1; depth1++) {
        for (i = 0; i < 8 && ptr8[i] != ' '; i++) {
            keyword[i] = ptr8[i];
        }
    }
}
