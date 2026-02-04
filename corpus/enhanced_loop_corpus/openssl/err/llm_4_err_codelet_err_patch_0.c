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
    for (; str->error != 0; str++) {
        if (plib > 0)
            str->error |= plib;
        else
            break;
    }
}
