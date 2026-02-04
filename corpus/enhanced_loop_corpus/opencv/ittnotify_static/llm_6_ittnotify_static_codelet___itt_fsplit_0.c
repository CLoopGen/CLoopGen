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
    int b;
    for (i = 0; s[i]; i++) {
        b = 0;
        for (j = 0; sep[j] && !b; j++) {
            b = (s[i] == sep[j]);
        }
        if (!b)
            break;
    }
}
