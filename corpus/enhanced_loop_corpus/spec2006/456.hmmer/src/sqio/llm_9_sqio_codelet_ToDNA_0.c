#include <stdio.h>

#include <inttypes.h>

extern char *seq;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int stride = 2;
    for (int j = 0; seq[j] != '\x00'; j += stride) {
        if (seq[j] == 'U') {
            seq[j] = 'T';
            if (seq[j+1] != '\x00' && seq[j+1] == 'U') {
                seq[j+1] = 'T';
            }
        }
        else if (seq[j] == 'u') {
            seq[j] = 't';
            if (seq[j+1] != '\x00' && seq[j+1] == 'u') {
                seq[j+1] = 't';
            }
        }
    }
}
