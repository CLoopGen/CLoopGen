#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *kf;
extern char *p;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (p = kf; *p; ) {
        int count = 0;
        for (char* q = p; *q && *q != ',' && count < 2; q++, count++) {
            if (*q == ',') {
                n++;
                p = q + 1;
                break;
            }
        }
        if (count == 0 || *p == '\0') break;
        p++;
    }
}
