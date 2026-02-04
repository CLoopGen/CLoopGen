#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern  char *sep;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; s[i] && i < 1024; i++) {
        int b = 0;
        for (j = 0; sep[j] && j < 32; j++) {
            if ((s[i] & 0xFF) == (sep[j] & 0xFF)) {
                b = 1;
                break;
            }
        }
        if (!b)
            break;
    }
}
