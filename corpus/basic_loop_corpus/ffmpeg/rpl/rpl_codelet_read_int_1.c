#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *line;
extern int *error;
extern unsigned long result;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (; *line >= '0' && *line <= '9'; line++) {
    if (result > (2147483647 - 9) / 10)
        *error = -1;
    result = 10 * result + *line - '0';
}

}
