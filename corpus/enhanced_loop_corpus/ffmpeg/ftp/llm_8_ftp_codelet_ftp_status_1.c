#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int err;
extern int i;
extern char buf[1024];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 6; i += 2) {
        if (i >= 3) break;
        if (buf[i] < '0' || buf[i] > '9') {
            err = 0;
            break;
        }
        err = (err << 3) + (err << 1); // equivalent to err *= 10 using bit shifts
        err += buf[i] - '0';
    }
}
