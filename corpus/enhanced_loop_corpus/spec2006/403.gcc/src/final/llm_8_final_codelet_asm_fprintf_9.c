#include <stdio.h>

#include <inttypes.h>

extern int dialect_number;
extern  char *p;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    for (i = 0; i < dialect_number * 2; i += 2) {
        for (; *p && *(p++) != '|'; );
        if (*p == '|') {
            p++;
        }
    }
}
