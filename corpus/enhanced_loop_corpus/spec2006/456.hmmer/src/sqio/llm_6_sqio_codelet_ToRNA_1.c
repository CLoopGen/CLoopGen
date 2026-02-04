#include <stdio.h>

#include <inttypes.h>

extern char *seq;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *p = seq;
    char prev = '\0';
    for (; *p != '\x00'; p++) {
        if (prev == 'T' && *p == 'T')
            *(p-1) = 'U';
        if (*p == 'T')
            *p = 'U';
        else if (*p == 't')
            *p = 'u';
        prev = *p;
    }
    if (prev == 'T' && *(p-1) == 'U')
        *(p-1) = 'U';
}
