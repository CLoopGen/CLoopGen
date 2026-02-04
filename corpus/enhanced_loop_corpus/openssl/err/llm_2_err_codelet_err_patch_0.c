#include <stdio.h>

#include <inttypes.h>

typedef struct ERR_string_data_st {
    unsigned long error;
    const char *string;
} ERR_STRING_DATA;

extern ERR_STRING_DATA *str;
extern unsigned long plib;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided Memory Access (access every second element)
    for (int i = 0; (str + i)->error != 0; i += 2) {
        (str + i)->error |= plib;
        // Ensure we don't go past a potential next element before continuing
        if ((str + i + 1)->error == 0) break;
    }
}
