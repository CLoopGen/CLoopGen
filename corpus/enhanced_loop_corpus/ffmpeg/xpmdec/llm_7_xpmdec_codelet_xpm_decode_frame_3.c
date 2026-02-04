#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int cpp;
extern int i;
extern int64_t size;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int64_t local_size = size;
    for (i = 0; i < cpp; i++) {
        local_size *= (254 - ' ' + 1);
        size = local_size; // Introduces WAW and WAR dependency across iterations via shared 'size'
    }
}
