#include <stdio.h>

#include <inttypes.h>

extern  char *name;
extern  char *base;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t i;
    size_t len = 0;
    const char *temp = name;
    while (*temp++) len++;
    base = name;
    for (i = 0; i < len; i++) {
        if ((name[i] == '/') && (i + 1 < len)) {
            base = (char *)&name[i + 1];
        }
    }
}
