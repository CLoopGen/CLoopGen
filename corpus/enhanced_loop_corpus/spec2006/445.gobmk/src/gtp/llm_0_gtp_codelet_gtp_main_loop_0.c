#include <stdio.h>

#include <inttypes.h>

extern char line[1000];
extern char *p;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0, p = line; line[i]; i++) {
    char c = line[i];
    if (c == 9)
        *p++ = 32;
    else if ((c > 0 && c <= 9) || (c >= 11 && c <= 31) || c == 127)
        continue;
    else if (c == '#')
        break;
    else
        *p++ = c;
}
}
