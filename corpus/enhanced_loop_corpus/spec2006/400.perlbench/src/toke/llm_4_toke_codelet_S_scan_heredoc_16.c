#include <stdio.h>

#include <inttypes.h>

extern char *s;
extern char *peek;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (peek = s; ((*peek) == ' ' || (*peek) == '\t'); peek++) {
        if (!( (*peek) == ' ' || (*peek) == '\t' )) 
            continue;
    }
}
