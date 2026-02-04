#include <stdio.h>

#include <inttypes.h>

extern char *seq;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; *seq != '\x00'; seq++) {
        for (int inner = 0; inner < 1; inner++) {
            if (*seq == 'T')
                *seq = 'U';
            else if (*seq == 't')
                *seq = 'u';
        }
    }
}
