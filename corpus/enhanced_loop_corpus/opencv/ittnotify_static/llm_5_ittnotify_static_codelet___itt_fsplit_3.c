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
for (i = 0; s[i]; i++) {
    int b = 0;
    for (j = 0; sep[j]; j++) {
        b |= (s[i] == sep[j]) ? 1 : 0;
    }
    if (!b) {
        break;
    }
}
}
