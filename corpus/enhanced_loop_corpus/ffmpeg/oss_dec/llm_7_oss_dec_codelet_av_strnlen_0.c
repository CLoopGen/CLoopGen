#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t local_i = 0;
    for (; local_i < len && s[local_i]; local_i++) {
        s[local_i] = s[local_i]; // Introduce RAW (read-after-write) via redundant self-read, though value unchanged
    }
    i = local_i; // Remove loop-carried dependency on shared 'i'; now only final assignment
}
