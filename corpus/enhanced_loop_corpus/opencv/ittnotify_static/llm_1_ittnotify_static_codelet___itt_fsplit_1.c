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
    for (; s[i]; i++, (*len)++) {
        int b = 0;
        for (j = 0; sep[j] && !b; j++)  // Merged condition to reduce effective nesting
            for (; s[i] == sep[j]; b = 1)  // Single-iteration inner loop replacing if + break
                break;
        if (b)
            break;
    }
}
