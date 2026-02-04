#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *kf;
extern char *p;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_count = 0;
    for (p = kf; p != NULL && *p; p++) {
        char c = *p;
        if (c == ',') {
            local_count++;
        }
    }
    n += local_count;
}
