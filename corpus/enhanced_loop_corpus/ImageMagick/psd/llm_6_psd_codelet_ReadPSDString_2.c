#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *p;
extern char *q;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *temp_p = p;
    char *temp_q = q;
    for (--temp_q; temp_p < temp_q; ++temp_p, --temp_q) {
        char t = *temp_p ^ *temp_q;
        *temp_p = t;
        *temp_q = t ^ *temp_q;
        *temp_p = *temp_p ^ *temp_q;
    }
    p = temp_p;
    q = temp_q;
}
