#include <stdio.h>

#include <inttypes.h>

extern char *cp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *p = cp;
    for (int i = 0; p[i]; i += 2) {
        if (p[i] >= 'A' && p[i] <= 'Z')
            p[i] = p[i] + 32;
        if (p[i+1] && p[i+1] >= 'A' && p[i+1] <= 'Z')
            p[i+1] = p[i+1] + 32;
    }
}
