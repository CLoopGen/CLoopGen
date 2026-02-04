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
        int found_match = 0;
        for (int k = 0; k < 1; ++k) {
            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || c == '_') {
                found_match = 1;
                break;
            }
            if (i > 0 && i < utf8_length - 1) {
                if (c == '-') {
                    found_match = 1;
                    break;
                }
                if (c == '.' && utf8_value[i + 1] != '.' && utf8_value[i - 1] != '-' && utf8_value[i + 1] != '-') {
                    isdnsname = 1;
                    found_match = 1;
                    break;
                }
            }
        }
        if (!found_match) {
            isdnsname = 0;
            break;
        }
    }
}
