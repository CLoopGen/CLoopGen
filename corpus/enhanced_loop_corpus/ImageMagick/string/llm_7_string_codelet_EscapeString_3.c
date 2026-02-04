#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *source;
extern  char escape;
extern char *q;
extern  char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char temp;
    char* local_q = q;
    for (p = source; *p != '\x00'; p++) {
        temp = *p;
        if ((temp == '\\') || (temp == escape))
            *(local_q++) = '\\';
        *(local_q++) = temp;
    }
    q = local_q;
}
