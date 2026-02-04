#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *line;
extern int64_t num;
extern int64_t den;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int64_t temp_num = 0;
    int64_t temp_den = 1;
    const char *ptr = line;

    for (; ptr[0] >= '0' && ptr[0] <= '9' && ptr[1] >= '0' && ptr[1] <= '9'; ptr += 2) {
        int64_t digit0 = ptr[0] - '0';
        int64_t digit1 = ptr[1] - '0';

        if (temp_num > ((9223372036854775807L) - 99) / 100ULL || 
            temp_den > (9223372036854775807L) / 100ULL)
            break;

        temp_num = temp_num * 100 + digit0 * 10 + digit1;
        temp_den *= 100;
    }

    // Handle remaining single digit if needed
    if (ptr[0] >= '0' && ptr[0] <= '9') {
        if (temp_num <= ((9223372036854775807L) - 9) / 10ULL && 
            temp_den <= (9223372036854775807L) / 10ULL) {
            temp_num = temp_num * 10 + (ptr[0] - '0');
            temp_den *= 10;
        }
        ptr++;
    }

    num = temp_num;
    den = temp_den;
    line = (char *)ptr;
}
