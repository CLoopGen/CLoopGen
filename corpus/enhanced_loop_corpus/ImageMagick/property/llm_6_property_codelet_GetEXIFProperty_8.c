#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *property;
extern size_t tag;
extern ssize_t i;
extern int c;
extern size_t n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ssize_t j;
    size_t temp_tag = 0;
    for (i = (ssize_t)n - 1L; i >= 0; i--) {
        c = property[i];
        temp_tag <<= 4;
        if ((c >= '0') && (c <= '9'))
            temp_tag |= (size_t)(c - '0');
        else if ((c >= 'A') && (c <= 'F'))
            temp_tag |= (size_t)(c - ('A' - 10));
        else if ((c >= 'a') && (c <= 'f'))
            temp_tag |= (size_t)(c - ('a' - 10));
        else
            return;
    }
    tag = temp_tag;
}
