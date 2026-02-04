#include <stdio.h>

#include <inttypes.h>

extern  char *host;
extern  size_t MAX_LABEL_LENGTH;
extern size_t i;
extern int isdnsname;
extern size_t length;
extern size_t label_length;
extern int all_numeric;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < length && label_length < MAX_LABEL_LENGTH; ++i) {
    char c = host[i];
    int valid_char = 0;

    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_') {
        label_length += 1;
        all_numeric = 0;
        valid_char = 1;
    }
    else if (c >= '0' && c <= '9') {
        label_length += 1;
        valid_char = 1;
    }
    else if (i > 0 && i < length - 1) {
        if (c == '-') {
            label_length += 1;
            valid_char = 1;
        }
        else if (c == '.' && host[i + 1] != '.' && host[i - 1] != '-' && host[i + 1] != '-') {
            label_length = 0;
            isdnsname = 1;
            valid_char = 1;
        }
    }

    if (!valid_char) {
        isdnsname = 0;
        break;
    }
}
}
