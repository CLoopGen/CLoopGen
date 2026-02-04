#include <stdio.h>

#include <inttypes.h>

extern  char *s;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    char *ptr = s;
    for (i = 0; ('0' <= ptr[i*1] && ptr[i*1] <= '9') || ('A' <= ptr[i*1] && ptr[i*1] <= 'F') || ('a' <= ptr[i*1] && ptr[i*1] <= 'f'); i++)
        ;
}
