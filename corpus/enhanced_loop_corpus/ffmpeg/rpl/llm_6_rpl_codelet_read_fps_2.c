#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *line;
extern int64_t num;
extern int64_t den;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int64_t temp_num = num;
    int64_t temp_den = den;
    char *ptr = line;

    for (; *ptr >= '0' && *ptr <= '9'; ptr++) {
        if (temp_num > ((9223372036854775807L) - 9) / 10ULL || temp_den > (9223372036854775807L) / 10ULL)
            break;
        temp_num = 10 * temp_num + (*ptr - '0');
        temp_den *= 10;
    }

    num = temp_num;
    den = temp_den;
    line = ptr;
}
