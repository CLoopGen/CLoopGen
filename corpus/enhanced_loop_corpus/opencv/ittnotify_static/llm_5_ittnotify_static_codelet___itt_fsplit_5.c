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
    for (; s[i] && i < INT32_MAX; i++) {
        for (j = 0; sep[j]; j++) {
            if (s[i] == sep[j])
                goto next_char;
        }
        break;
        next_char:;
    }
}
