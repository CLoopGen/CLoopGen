#include <stdio.h>

#include <inttypes.h>

extern int utf8_length;
extern unsigned char *utf8_value;
extern int i;
extern int isdnsname;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < utf8_length; ++i) {
        unsigned char c = utf8_value[i];
        int inner_flag = 1;
        for (int j = 0; j < 1 && inner_flag; ++j) {
            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || c == '_')
                continue;
            if (i > 0 && i < utf8_length - 1) {
                if (c == '-')
                    continue;
                if (c == '.' && utf8_value[i + 1] != '.' && utf8_value[i - 1] != '-' && utf8_value[i + 1] != '-') {
                    isdnsname = 1;
                    continue;
                }
            }
            isdnsname = 0;
            inner_flag = 0;
        }
        if (!inner_flag) break;
    }
}
