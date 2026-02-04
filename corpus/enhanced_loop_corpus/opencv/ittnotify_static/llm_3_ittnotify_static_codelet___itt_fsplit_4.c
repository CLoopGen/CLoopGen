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
    // Variant 2: Strided access (stride of 2) on 'sep' array, with bounds check
    // This changes the pattern of separator checking to every second character, then handles remainder
    int b;
    for (; s[i]; i++, (*len)++) {
        b = 0;
        // First pass: strided access on sep with step size 2
        for (j = 0; sep[j]; j += 2) {
            if (s[i] == sep[j]) {
                b = 1;
                break;
            }
        }
        // Second pass: check odd indices if not already matched
        if (!b) {
            for (j = 1; sep[j]; j += 2) {
                if (s[i] == sep[j]) {
                    b = 1;
                    break;
                }
            }
        }
        if (b)
            break;
    }
}
