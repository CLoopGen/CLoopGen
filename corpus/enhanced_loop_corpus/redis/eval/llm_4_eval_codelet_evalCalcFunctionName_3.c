#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *out_funcname;
extern int j;
extern char *sha;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 0; j < 40; j++) {
        char c = sha[j];
        if (!(c >= 'A' && c <= 'Z')) continue;
        out_funcname[j + 2] = c + ('a' - 'A');
    }
}
