#include <stdio.h>

#include <inttypes.h>

extern int dialect_number;
extern  char *p;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int local_i;
    char *local_p = p;
    for (local_i = 0; local_i < dialect_number; local_i++) {
        for (; *local_p != '\0' && *(local_p++) != '|'; );
        if (*local_p == '|') {
            local_p++;
        }
    }
    p = local_p;
}
