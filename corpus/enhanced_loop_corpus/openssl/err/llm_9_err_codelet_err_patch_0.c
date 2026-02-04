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
    for (int i = 0; i < 2 && str[i].error != 0; i++) {
        str[i].error |= plib;
        str[i].error = (str[i].error << 1) | (str[i].error >> 31);
    }
}
