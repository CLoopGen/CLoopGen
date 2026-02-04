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
    for (i = 0; s[i]; i += 1) {
        int b = 0;
        // Use strided access on sep with stride of 1 (normal sequential, but expressed explicitly)
        for (j = 0; sep[j] != '\0'; j += 1) {
            if (*(s + i) == *(sep + j)) {
                b = 1;
                break;
            }
        }
        if (!b)
            break;
    }
}
