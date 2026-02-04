#include <stdio.h>

#include <inttypes.h>

extern char *seq;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; *seq != '\x00'; seq++) {
        if (*seq != 'U' && *seq != 'u')
            continue;
        if (*seq == 'U') {
            *seq = 'T';
            continue;
        }
        if (*seq == 'u') {
            *seq = 't';
        }
    }
}
