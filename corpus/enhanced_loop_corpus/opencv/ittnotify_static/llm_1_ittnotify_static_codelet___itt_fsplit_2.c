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
    for (; s[i]; i++) {
        int b = 0;
        for (j = 0; sep[j] && !b; j++)
            for (int k = 0; k < 1 && s[i] == sep[j]; k++)
                b = 1;
        if (!b)
            break;
    }
}
