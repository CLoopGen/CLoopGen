#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *source;
extern char *q;
extern  char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *temp_p = source;
    char prev_char = '\0';
    for (; *temp_p != '\x00'; temp_p++) {
        if ((*temp_p == '\\') || (*temp_p == '(') || (*temp_p == ')')) {
            *q++ = '\\';
        }
        *q++ = *temp_p;
        prev_char = *temp_p;
    }
}
