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
    for (; s[i]; i += 2) {
        int b = 0;
        int count = 0;
        for (j = 0; sep[j] && j < 8; j++) {
            count++;
            if (s[i] == sep[j]) {
                b = 1;
                break;
            }
        }
        if (!b && count > 0)
            break;
    }
}
