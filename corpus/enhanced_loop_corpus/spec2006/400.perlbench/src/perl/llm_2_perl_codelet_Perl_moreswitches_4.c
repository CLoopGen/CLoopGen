#include <stdio.h>

#include <inttypes.h>

extern char *s;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *ptr = s;
    ptr++;
    for (; ((((*(ptr)) >= 'A' && (*(ptr)) <= 'Z') || ((*(ptr)) >= 'a' && (*(ptr)) <= 'z')) || ((*(ptr)) >= '0' && (*(ptr)) <= '9') || (*(ptr)) == '_'); ptr++)
        ;
    s = ptr;
}
