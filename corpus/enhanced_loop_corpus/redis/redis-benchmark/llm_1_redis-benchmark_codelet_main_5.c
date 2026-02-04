#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef char *sds;

extern int i;
extern char *data;
extern  char *cmd_argv[21];
extern sds key_placeholder;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < 11; i++) {
        int index = 2 * i;
        cmd_argv[index] = key_placeholder;
        cmd_argv[index + 1] = data;
    }
}
