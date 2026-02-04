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
    for (i = 0; s[i]; i += 2) {
        int b = 0;
        for (j = 0; sep[j]; j++) {
            b |= (s[i] == sep[j]) ? 1 : 0;
        }
        if (!b) {
            i--; // Adjust index to ensure correct exit point
            break;
        }
        if (s[i+1] == '\0') break;
    }
    if (s[i] == '\0' && i > 0) i--; // Ensure i points to valid char if possible
}
