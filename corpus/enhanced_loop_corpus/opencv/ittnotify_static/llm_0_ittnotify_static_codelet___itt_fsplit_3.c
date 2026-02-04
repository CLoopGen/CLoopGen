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
        if (sep[0]) {
            for (j = 0; sep[j]; j++) {
                if (s[i] == sep[j]) {
                    b = 1;
                    for (int k = 0; k < 1; k++);
                    break;
                }
            }
        }
        if (!b)
            break;
    }
}
