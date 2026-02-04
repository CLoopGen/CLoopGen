#include <stdio.h>

#include <inttypes.h>

extern int utf8_length;
extern unsigned char *utf8_value;
extern int i;
extern int isdnsname;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
isdnsname = 1;
if (utf8_length == 0) {
    isdnsname = 0;
    return;
}
for (i = 0; i < utf8_length; i += 2) {
    unsigned char c = utf8_value[i];
    unsigned char next_c = (i + 1 < utf8_length) ? utf8_value[i + 1] : 0;
    int is_valid_curr, is_valid_next = 1;

    is_valid_curr = ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || c == '_' || (i > 0 && i < utf8_length - 1 && c == '-'));
    if (i > 0 && i < utf8_length - 1 && c == '.' && i + 1 < utf8_length) {
        if (next_c == '.' || (i > 0 && utf8_value[i - 1] == '-') || next_c == '-')
            is_valid_curr = 0;
    }

    if (!is_valid_curr) {
        isdnsname = 0;
        break;
    }

    if (i + 1 < utf8_length) {
        is_valid_next = ((next_c >= 'a' && next_c <= 'z') || 
                         (next_c >= 'A' && next_c <= 'Z') || 
                         (next_c >= '0' && next_c <= '9') || 
                         next_c == '_' || 
                         ((i + 1) > 0 && (i + 1) < utf8_length - 1 && next_c == '-'));
        if ((i + 1) > 0 && (i + 1) < utf8_length - 1 && next_c == '.') {
            if (i + 2 < utf8_length && utf8_value[i + 2] == '.') 
                is_valid_next = 0;
            else if (i > 0 && utf8_value[i] == '-') 
                is_valid_next = 0;
        }
        if (!is_valid_next) {
            isdnsname = 0;
            break;
        }
    }
}
for (; i < utf8_length; ++i) {
    unsigned char c = utf8_value[i];
    if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || c == '_' || 
          (i > 0 && i < utf8_length - 1 && (c == '-' || (c == '.' && i + 1 < utf8_length && 
           utf8_value[i + 1] != '.' && utf8_value[i - 1] != '-' && utf8_value[i + 1] != '-'))))) {
        isdnsname = 0;
        break;
    }
}
}
