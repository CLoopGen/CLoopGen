#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *out_funcname;
extern int j;
extern char *sha;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 0; j < 80; j += 2) {
        char c = sha[j];
        out_funcname[j + 2] = (c >= 'A' && c <= 'Z') ? c + 32 : c;
        out_funcname[j + 3] = (j + 1 < 40) ? ((sha[j + 1] >= 'A' && sha[j + 1] <= 'Z') ? sha[j + 1] + 32 : sha[j + 1]) : '\0';
    }
}
