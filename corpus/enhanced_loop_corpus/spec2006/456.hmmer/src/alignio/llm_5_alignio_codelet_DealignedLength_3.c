#include <stdio.h>

#include <inttypes.h>

extern char *aseq;
extern int rlen;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    rlen = 0;
    for (; *aseq; aseq++) {
        int is_valid = 1;
        if ((*aseq) == ' ') is_valid = 0;
        else if ((*aseq) == '.') is_valid = 0;
        else if ((*aseq) == '_') is_valid = 0;
        else if ((*aseq) == '-') is_valid = 0;
        else if ((*aseq) == '~') is_valid = 0;
        if (is_valid) rlen++;
    }
}
