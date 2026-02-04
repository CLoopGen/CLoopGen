#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *line;
extern int *error;
extern unsigned long result;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned long temp = 0;
    char *ptr = line;
    int err = 0;
    size_t count = 0;
    const size_t max_digits = 10; 

    for (; *ptr >= '0' && *ptr <= '9' && count < max_digits; ptr++, count++) {
        if (temp > (2147483647 - (*ptr - '0')) / 10)
            err = -1;
        temp = temp * 10 + (*ptr - '0');
    }

    if (err == -1) {
        *error = -1;
    } else {
        result = temp;
        line = ptr;
    }
}
