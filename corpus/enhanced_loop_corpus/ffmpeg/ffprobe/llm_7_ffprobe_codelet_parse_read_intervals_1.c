#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int n;
extern char *p;
extern char *spec;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_n = n;
    char *local_p = spec;
    while (1) {
        if (!*local_p) break;
        if (*local_p == ',') {
            local_n++;
        }
        local_p++;
    }
    n = local_n;
    p = local_p;
}
