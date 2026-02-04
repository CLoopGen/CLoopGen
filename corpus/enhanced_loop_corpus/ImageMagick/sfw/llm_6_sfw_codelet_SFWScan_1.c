#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  unsigned char *p;
extern  unsigned char *target;
extern  size_t length;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ssize_t local_i;
    unsigned char temp_p, temp_target;
    for (local_i = 0; local_i < (ssize_t)length; local_i++) {
        temp_p = p[local_i];
        temp_target = target[local_i];
        if (temp_p != temp_target)
            break;
    }
    i = local_i;
}
