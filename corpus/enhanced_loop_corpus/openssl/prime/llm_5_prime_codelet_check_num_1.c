#include <stdio.h>

#include <inttypes.h>

extern  char *s;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; ; i++) {
        if (!(s[i] >= '0' && s[i] <= '9')) break;
    }
}
