#include <stdio.h>

#include <inttypes.h>

extern char *aseq;
extern int rlen;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    rlen = 0;
    int i;
    for (i = 0; *(aseq + i); i += 2) {
        char c = *(aseq + i);
        if (!(c == ' ' || c == '.' || c == '_' || c == '-' || c == '~'))
            rlen++;
        if (*(aseq + i + 1) == '\0') break;
    }
    for (i = 1; *(aseq + i); i += 2) {
        char c = *(aseq + i);
        if (!(c == ' ' || c == '.' || c == '_' || c == '-' || c == '~'))
            rlen++;
    }
}
