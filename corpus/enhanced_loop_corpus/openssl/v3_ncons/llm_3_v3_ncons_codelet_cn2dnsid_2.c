#include <stdio.h>

#include <inttypes.h>

extern int utf8_length;
extern unsigned char *utf8_value;
extern int i;
extern int isdnsname;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Reverse Consecutive Memory Access (iterate from end to beginning)
    isdnsname = 1;

    for (i = utf8_length - 1; i >= 0; --i) {
        unsigned char c = utf8_value[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || c == '_')
            continue;

        if (i > 0 && i < utf8_length - 1) {
            if (c == '-')
                continue;
            if (c == '.' && (i + 1 >= utf8_length || utf8_value[i + 1] != '.') &&
                      (i - 1 >= 0 && utf8_value[i - 1] != '-') &&
                      (i + 1 < utf8_length && utf8_value[i + 1] != '-')) {
                continue;
            }
        }
        isdnsname = 0;
        break;
    }
}
