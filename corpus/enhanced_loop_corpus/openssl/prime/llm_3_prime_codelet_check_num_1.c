#include <stdio.h>

#include <inttypes.h>

extern  char *s;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int stride = 1;
    for (i = 0; s[i] != '\0' && '0' <= s[i] && s[i] <= '9'; i += stride)
        ;
}
