#include <stdio.h>

#include <inttypes.h>

extern char *seq;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; *seq != '\x00'; seq++) {
        if (*seq == 'T') {
            *seq = 'U';
            continue;
        }
        if (*seq == 't')
            *seq = 'u';
    }
}
