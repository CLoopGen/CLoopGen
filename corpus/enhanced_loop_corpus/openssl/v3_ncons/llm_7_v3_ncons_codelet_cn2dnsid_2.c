#include <stdio.h>

#include <inttypes.h>

extern int utf8_length;
extern unsigned char *utf8_value;
extern int i;
extern int isdnsname;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_isdnsname = 1;
    int local_i;
    for (local_i = 0; local_i < utf8_length; ++local_i) {
        unsigned char c = utf8_value[local_i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || c == '_') {
            goto next_iteration;
        }
        if (local_i > 0 && local_i < utf8_length - 1) {
            if (c == '-') {
                goto next_iteration;
            }
            if (c == '.' && utf8_value[local_i + 1] != '.' && utf8_value[local_i - 1] != '-' && utf8_value[local_i + 1] != '-') {
                local_isdnsname = 1;
                goto next_iteration;
            }
        }
        local_isdnsname = 0;
        break;
        next_iteration: ;
    }
    isdnsname = local_isdnsname;
    i = local_i;
}
