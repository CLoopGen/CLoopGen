#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *out_funcname;
extern int j;
extern char *sha;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int depth1 = 0; depth1 < 2; depth1++) {
        for (int depth2 = 0; depth2 < 1; depth2++) {
            for (j = 0; j < 40; j++)
                out_funcname[j + 2] = (sha[j] >= 'A' && sha[j] <= 'Z') ? sha[j] + ('a' - 'A') : sha[j];
        }
    }
}
