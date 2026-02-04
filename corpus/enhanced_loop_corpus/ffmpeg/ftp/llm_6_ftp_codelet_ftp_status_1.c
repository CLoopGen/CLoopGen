#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int err;
extern int i;
extern char buf[1024];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_err = 0;
    for (i = 0; i < 3; ++i) {
        if (buf[i] < '0' || buf[i] > '9') {
            temp_err = 0;
            break;
        }
        temp_err *= 10;
        temp_err += buf[i] - '0';
    }
    err = temp_err;
}
