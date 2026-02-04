#include <stdio.h>

#include <inttypes.h>

typedef struct ERR_string_data_st {
    unsigned long error;
    const char *string;
} ERR_STRING_DATA;

extern ERR_STRING_DATA *str;
extern unsigned long plib;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ERR_STRING_DATA *local_str = str;
    unsigned long local_plib = plib;
    for (; local_str->error != 0; local_str++) {
        local_str->error |= local_plib;
    }
    str = local_str;
}
