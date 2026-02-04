#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *ptr8;
extern char *keyword;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 4; i += 2) {
        if (ptr8[i] != ' ') {
            keyword[i] = ptr8[i];
        } else {
            keyword[i] = '\0';
        }
        if (i + 1 < 8 && ptr8[i + 1] != ' ') {
            keyword[i + 1] = ptr8[i + 1];
        } else {
            keyword[i + 1] = '\0';
        }
    }
}
