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
    for (; s[i] && s[i+1]; i++) {
        int b1 = 0, b2 = 0;
        for (j = 0; sep[j]; j++) {
            if (s[i] == sep[j]) b1 = 1;
            if (s[i+1] == sep[j]) b2 = 1;
        }
        if (!b1 || !b2)
            break;
    }
}
