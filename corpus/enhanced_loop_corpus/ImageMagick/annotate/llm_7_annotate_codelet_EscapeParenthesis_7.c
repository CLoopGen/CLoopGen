#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *source;
extern char *q;
extern  char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *local_p = source;
    char *local_q = q;
    for (; *local_p != '\x00'; local_p++) {
        if ((*local_p == '\\') || (*local_p == '(') || (*local_p == ')')) {
            *local_q++ = '\\';
        }
        *local_q++ = *local_p;
    }
    q = local_q;
}
