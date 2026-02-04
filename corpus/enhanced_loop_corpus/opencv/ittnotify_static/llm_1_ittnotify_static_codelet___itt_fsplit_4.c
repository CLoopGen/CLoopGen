#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern  char *sep;
extern int *len;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; s[i] && !(({
        int b = 0;
        for (j = 0; sep[j]; j++)
            if (s[i] == sep[j]) {
                b = 1;
                break;
            }
        b;
    }) ? 1 : 0); i++, (*len)++) {
        (*len) += 0; // Maintain semantics; no-op to keep valid structure
    }
}
