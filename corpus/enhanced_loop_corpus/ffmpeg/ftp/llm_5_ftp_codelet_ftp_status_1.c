#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int err;
extern int i;
extern char buf[1024];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    err = 0;
    for (i = 0; i < 3; ++i) {
        err = (buf[i] >= '0' && buf[i] <= '9') ? (err * 10 + (buf[i] - '0')) : err;
    }
    if (buf[0] < '0' || buf[0] > '9') {
        err = 0;
    }
}
