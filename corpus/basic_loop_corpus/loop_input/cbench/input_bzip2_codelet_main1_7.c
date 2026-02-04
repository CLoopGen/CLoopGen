#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>

typedef char Char;

Char *progName;
Char progNameReally[1034];
Char *tmp;

void init_vars() {
    for (int i = 0; i < 1033; i++) {
        progNameReally[i] = 'a' + (i % 26);
    }
    progNameReally[1033] = '\x00';

    int slash_pos = 700;
    progNameReally[slash_pos] = '/';

    progName = &progNameReally[0];
    tmp = &progNameReally[0];
}