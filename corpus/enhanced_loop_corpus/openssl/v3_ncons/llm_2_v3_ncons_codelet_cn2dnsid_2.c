#include <stdio.h>

#include <inttypes.h>

extern int utf8_length;
extern unsigned char *utf8_value;
extern int i;
extern int isdnsname;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided Memory Access (process every 2nd element in forward pass, then handle remainder)
    isdnsname = 1;
    int stride = 2;
    int processed = 0;

    // Strided access: traverse with step size 2
    for (i = 0; i < utf8_length; i += stride) {
        unsigned char c = utf8_value[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || c == '_')
            continue;

        if (i > 0 && i < utf8_length - 1) {
            if (c == '-')
                continue;
            if (c == '.' && (i + 1 >= utf8_length || utf8_value[i + 1] != '.') &&
                          (i - 1 < utf8_length && utf8_value[i - 1] != '-') &&
                          (i + 1 < utf8_length && utf8_value[i + 1] != '-')) {
                continue;
            }
        }
        isdnsname = 0;
        break;
    }

    // Handle odd-indexed elements if stride skipped any
    if (isdnsname && utf8_length > 1) {
        for (i = 1; i < utf8_length; i += stride) {
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
}
