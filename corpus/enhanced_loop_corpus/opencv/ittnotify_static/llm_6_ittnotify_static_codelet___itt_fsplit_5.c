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
    int b = 0;
    for (; s[i]; i++) {
        b = 0;
        for (j = 0; sep[j]; j++) {
            if (sep[j] == s[i]) {
                b = 1;
                break;
            }
        }
        if (!b)
            break;
        // Introduce a WAW dependency on 'b' via redundant assignment
        b = b; 
    }
}
