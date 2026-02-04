#include <stdio.h>

#include <inttypes.h>

extern int dialect_number;
extern  char *p;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int stride = 1;
    for (i = 0; i < dialect_number; i++) {
        char val;
        for (int j = 0; (val = p[j * stride]) != '\0' && val != '}' && val != '|'; j++)
            ;
        if (p[i * stride] == '}')
            break;
        if (p[i * stride] == '|')
            p += stride;
    }
}
