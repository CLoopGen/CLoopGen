#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *kf;
extern char *p;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    for (p = kf, n = 0; *p != '\0'; p += 2) {
        if (*(p) == ',') {
            n++;
        }
        if (*(p + 1) == ',' && *(p + 1) != '\0') {
            n++;
        }
    }
    if (*(p - 1) == ',' && ((p - kf) & 1) == 0) {
        n--;
    }
}
