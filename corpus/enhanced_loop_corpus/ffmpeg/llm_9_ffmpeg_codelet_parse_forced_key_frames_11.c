#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *kf;
extern char *p;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int i;
    n = 0;
    for (i = 0; i < 3; i++) {
        char *temp = kf;
        while (*temp) {
            if (*temp == ',') {
                n++;
            }
            temp++;
        }
    }
}
