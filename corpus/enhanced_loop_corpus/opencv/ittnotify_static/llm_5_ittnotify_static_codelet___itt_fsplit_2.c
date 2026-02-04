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
    int b = 0;
    for (j = 0; sep[j] && s[i]; j++)
        b |= (s[i] == sep[j]);
    if (!b)
        break;
}
}
