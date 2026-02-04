#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>

typedef char Char;

Char progNameReally[1034];
Char *progName;
Char *tmp;

void init_vars() {
    for (int i = 0; i < 1033; i++) {
        progNameReally[i] = 'a';
    }
    progNameReally[1033] = '\x00';

    for (int i = 100; i < 1030; i += 20) {
        progNameReally[i] = '/';
    }

    tmp = NULL;
    progName = &progNameReally[0];
}