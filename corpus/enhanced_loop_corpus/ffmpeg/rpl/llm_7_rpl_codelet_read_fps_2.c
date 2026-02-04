#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *line;
extern int64_t num;
extern int64_t den;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int64_t local_num = num;
    int64_t local_den = den;
    char *local_line = line;

    for (; *(volatile char*)local_line >= '0' && *(volatile char*)local_line <= '9'; ) {
        int64_t digit = *(local_line) - '0';
        int64_t new_num = 10 * local_num + digit;
        int64_t new_den = 10 * local_den;

        if (local_num > ((9223372036854775807L) - 9) / 10ULL || local_den > (9223372036854775807L) / 10ULL)
            break;

        local_num = new_num;
        local_den = new_den;
        local_line++;
    }

    num = local_num;
    den = local_den;
    line = local_line;
}
