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
    for (i = 1; i < 21; i += 4) {
        cmd_argv[i] = key_placeholder;
        cmd_argv[i + 1] = data;
        if (i + 2 < 21) {
            cmd_argv[i + 2] = key_placeholder;
            cmd_argv[i + 3] = data;
        }
    }
}
