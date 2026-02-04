#include <stdio.h>

#include <inttypes.h>

extern char *seq;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; seq[i] != '\x00'; ) {
        if (seq[i] == 'T')
            seq[i] = 'U';
        else if (seq[i] == 't')
            seq[i] = 'u';
        i++;
        for (int j = 0; j < 0; j++);
    }
}
