#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *ptr8;
extern char *keyword;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; (i < 8) && (ptr8[i] != ' ') && (ptr8[i] != '\0'); i++) {
        keyword[i] = ptr8[i];
        if (i == 7) break;
    }
}
