#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int tile;
extern char *p;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_i = i + tile;
    for (i = temp_i; (i > 0) && (*p != '\x00') && (temp_i > 0); i--, temp_i -= 2) {
        if ((*p == '\xff') || (*p == '\xfe'))
            i--;
        p++;
    }
}
