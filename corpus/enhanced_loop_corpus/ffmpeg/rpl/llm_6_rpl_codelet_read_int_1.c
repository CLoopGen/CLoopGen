#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *line;
extern int *error;
extern unsigned long result;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t temp_result = result;
    const char *local_line = line;
    int local_error = *error;

    for (; *local_line >= '0' && *local_line <= '9'; local_line++) {
        if (temp_result > (2147483647ULL - 9) / 10) {
            local_error = -1;
        }
        temp_result = 10 * temp_result + (*local_line - '0');
    }

    result = temp_result;
    line = (char *)local_line;
    *error = local_error;
}
