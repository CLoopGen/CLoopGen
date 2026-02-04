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
    for (i = 0; i < 1; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (buf[j] < '0' || buf[j] > '9') {
                err = -1;
                goto exit_loop;
            }
            err = err * 10 + (buf[j] - '0');
        }
        exit_loop:;
    }
}
