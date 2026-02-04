#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *out_funcname;
extern int j;
extern char *sha;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access (access every 2nd element in reverse order with stride)
    for (j = 39; j >= 0; j -= 2) {
        out_funcname[j + 2] = (sha[j] >= 'A' && sha[j] <= 'Z') ? sha[j] + ('a' - 'A') : sha[j];
    }
    // Fill skipped indices in a second pass with stride 2 starting at j=38
    for (j = 38; j >= 0; j -= 2) {
        out_funcname[j + 2] = (sha[j] >= 'A' && sha[j] <= 'Z') ? sha[j] + ('a' - 'A') : sha[j];
    }
}
