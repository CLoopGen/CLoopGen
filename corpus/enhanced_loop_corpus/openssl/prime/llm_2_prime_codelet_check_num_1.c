#include <stdio.h>

#include <inttypes.h>

extern  char *s;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int j;
    for (j = 0; s[j] != '\0'; j++) {
        if (s[j] < '0' || s[j] > '9') break;
    }
    i = j;
}
