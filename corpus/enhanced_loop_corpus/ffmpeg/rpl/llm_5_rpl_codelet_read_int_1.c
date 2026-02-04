#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *line;
extern int *error;
extern unsigned long result;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; *line >= '0' && *line <= '9' && *error == 0; line++) {
        unsigned long new_result = 10 * result + *line - '0';
        if (new_result < result || new_result > 2147483647)
            *error = -1;
        else
            result = new_result;
    }
}
