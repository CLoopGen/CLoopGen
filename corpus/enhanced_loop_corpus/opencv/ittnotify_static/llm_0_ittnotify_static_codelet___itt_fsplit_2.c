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
        j = 0;
        if (sep[j]) {
            do {
                if (s[i] == sep[j]) {
                    b = 1;
                    break;
                }
                j++;
            } while (sep[j]);
        }
        if (!b)
            break;
    }
}
