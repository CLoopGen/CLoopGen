#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *string;
extern  char *reject;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int local_index = 0;
    int skip_flag = 0;

    for (i = 0; string && string[i]; i++) {
        skip_flag = 0;

        // Introduce WAW dependency via temporary
        local_index = i;

        if (string[local_index] == '/' && string[local_index + 1] == '*') {
            for (int k = local_index + 2; string && string[k]; k++) {
                if (string[k] == '*' && string[k + 1] == '/') {
                    skip_flag = k + 2 - local_index;
                    break;
                }
            }
            if (skip_flag > 0) {
                i = local_index + skip_flag - 1;
            }
        } else if (string[local_index] == '/' && string[local_index + 1] == '/') {
            for (int k = local_index + 2; string && string[k]; k++) {
                if (string[k] == '\n') {
                    skip_flag = k - local_index;
                    break;
                }
            }
            if (skip_flag > 0) {
                i = local_index + skip_flag - 1;
            }
        } else {
            for (j = 0; reject && reject[j]; j++) {
                if (string[local_index] == reject[j]) {
                    skip_flag = -1;
                    break;
                }
            }
            if (skip_flag == -1) {
                break;
            }
        }

        // Introduce artificial RAW dependency
        local_index = 0; // Overwrite to create write-after-write with prior use
    }
}
