#include <stdio.h>

#include <inttypes.h>

extern  char *s;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; s[i] != '\0'; i++) {
        char c = s[i];
        if ((c >= '0' && c <= '9')) continue;
        if ((c >= 'A' && c <= 'F')) continue;
        if ((c >= 'a' && c <= 'f')) continue;
        break;
    }
}
