#include <stdio.h>

#include <inttypes.h>

extern char *seq;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (; *seq != '\x00' && *(seq + 1) != '\x00'; seq += 2) {
    if (*seq == 'U')
        *seq = 'T';
    else if (*seq == 'u')
        *seq = 't';
    if (*(seq + 1) == 'U')
        *(seq + 1) = 'T';
    else if (*(seq + 1) == 'u')
        *(seq + 1) = 't';
}
}
