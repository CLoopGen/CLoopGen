#include <stdio.h>

#include <inttypes.h>

extern char *cp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *local_cp = cp;
    char prev = '\0';
    for (; *local_cp; local_cp++) {
        prev = ((*local_cp >= 'a') && (*local_cp <= 'z')) ? *local_cp - 32 : *local_cp;
        *local_cp = prev;
    }
}
