#include <stdio.h>

#include <inttypes.h>

extern char *seq;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (; *seq != '\x00'; seq++) {
    for (int i = 0; i < 1; i++) {
        if (*seq == 'U')
            *seq = 'T';
        else if (*seq == 'u')
            *seq = 't';
    }
}
}
