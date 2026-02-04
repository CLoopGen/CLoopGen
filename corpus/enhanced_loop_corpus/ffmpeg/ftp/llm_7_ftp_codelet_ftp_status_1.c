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
    int prev_err = 0;
    for (i = 0; i < 3; ++i) {
        int digit = buf[i] - '0';
        int is_digit = (buf[i] >= '0' && buf[i] <= '9');
        err = is_digit ? (prev_err * 10 + digit) : 0;
        prev_err = err;
    }
}
