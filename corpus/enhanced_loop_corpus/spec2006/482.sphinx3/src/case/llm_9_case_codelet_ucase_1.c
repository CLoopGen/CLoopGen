#include <stdio.h>

#include <inttypes.h>

extern char *cp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    for (i = 0; cp[i]; i += 2) {
        if (cp[i] >= 'a' && cp[i] <= 'z') {
            cp[i] = cp[i] - 32;
        }
        if (cp[i+1] && cp[i+1] >= 'a' && cp[i+1] <= 'z') {
            cp[i+1] = cp[i+1] - 32;
        }
    }
}
