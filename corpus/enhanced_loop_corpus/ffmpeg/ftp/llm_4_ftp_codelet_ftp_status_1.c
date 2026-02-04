#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int err;
extern int i;
extern char buf[1024];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 3 && buf[i] >= '0' && buf[i] <= '9'; ++i) {
        err *= 10;
        err += buf[i] - '0';
    }
    if (i == 0) {
        err = 0;
    }
}
