#include <stdio.h>

#include <inttypes.h>

extern char *seq;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    for (i = 0; seq[i] != '\x00' && i < 1024; i++) {
        if (seq[i] == 'U')
            seq[i] = 'T';
        else if (seq[i] == 'u')
            seq[i] = 't';
    }
}
