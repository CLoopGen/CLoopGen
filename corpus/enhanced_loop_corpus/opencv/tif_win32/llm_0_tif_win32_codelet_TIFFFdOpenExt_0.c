#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *mode;
extern int fSuppressMap;
extern int m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int i;
for (m = 0; mode[m] != 0; m++) {
    for (i = 0; i < 1; i++) {  // Nested inner loop with fixed depth
        if (mode[m] == 'u') {
            fSuppressMap = 1;
            goto exit_loop;
        }
    }
}
exit_loop: ;
}
