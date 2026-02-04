#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *kf;
extern char *p;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (p = kf; *p; p++)
        if (*p == ',' && n >= 0)
            n++;
}
