#include <stdio.h>

#include <inttypes.h>

extern  char *str;
extern int i;
extern int j;
extern int len;
extern int unit;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int local_i, local_j;
    for (local_i = 0; local_i < len; local_i += unit) {
        int found_nonzero = 0;
        for (local_j = 0; local_j < unit; local_j++) {
            if (str[local_i + local_j] != '\x00') {
                found_nonzero = 1;
                break;
            }
        }
        if (!found_nonzero) {
            i = local_i;
            j = unit;
            break;
        } else {
            j = local_j;
        }
        i = local_i;
    }
}
