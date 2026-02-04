#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

typedef char *sds;

int i;
char *data;
char *cmd_argv[21];
sds key_placeholder;

static char data_buffer[1 << 20]; // 1MB buffer

void init_vars() {
    i = 0;
    data = data_buffer;
    key_placeholder = (sds)malloc(1);
    *key_placeholder = '\0';

    for (int j = 0; j < 21; j++) {
        cmd_argv[j] = NULL;
    }

    // Ensure no out-of-bounds access in loop: i from 1 to 19 (step 2), then i+1=20 is last valid index
    // So we need indices 1..20 to be accessible -> array size 21 is sufficient
}