#include <stdio.h>

#include <inttypes.h>

extern int dialect_number;
extern  char *p;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int limit = dialect_number + (dialect_number >> 1);
    for (i = 0; i < limit; i++) {
        for (; *p && *(p++) != '|'; );
        if (i % 3 == 0 && *p == '|') {
            p++;
        }
    }
}
