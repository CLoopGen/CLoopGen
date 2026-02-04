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
    for (j = 0; sep[j]; j++)
        if (s[i] == sep[j]) {
            b = 1;
            break;
        }
    if (!b)
        break;
}

}
