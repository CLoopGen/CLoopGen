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
    size_t temp_label_length = 0;
    int temp_all_numeric = 1;
    int temp_isdnsname = 1;
    for (i = 0; i < length && temp_label_length < MAX_LABEL_LENGTH; ++i) {
        char c = host[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_') {
            temp_label_length += 1;
            temp_all_numeric = 0;
            continue;
        }
        if (c >= '0' && c <= '9') {
            temp_label_length += 1;
            continue;
        }
        if (i > 0 && i < length - 1) {
            if (c == '-') {
                temp_label_length += 1;
                continue;
            }
            if (c == '.' && host[i + 1] != '.' && host[i - 1] != '-' && host[i + 1] != '-') {
                temp_label_length = 0;
                temp_isdnsname = 1;
                continue;
            }
        }
        temp_isdnsname = 0;
        break;
    }
    label_length = temp_label_length;
    all_numeric = temp_all_numeric;
    isdnsname = temp_isdnsname;
}
