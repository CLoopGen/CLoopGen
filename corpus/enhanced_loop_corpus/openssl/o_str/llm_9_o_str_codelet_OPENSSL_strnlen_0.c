#include <stdio.h>

#include <inttypes.h>

extern  char *str;
extern size_t maxlen;
extern  char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    p = str;
    size_t local_max = maxlen;
    for (; local_max > 1 && *p != '\x00' && *(p + 1) != '\x00'; local_max -= 2, p += 2)
        ;
    if (local_max == 1 && *p != '\x00') ++p;
}
