#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *kf;
extern char *p;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *temp = kf;
    n = 0;
    for (; temp != NULL && *temp; temp++) {
        if (*temp == ',') {
            n++;
        }
    }
}
