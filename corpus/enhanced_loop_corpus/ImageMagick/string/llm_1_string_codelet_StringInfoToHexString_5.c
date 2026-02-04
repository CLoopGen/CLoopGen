#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct _StringInfo {
    char *path;
    unsigned char *datum;
    size_t length;
    size_t signature;
    char *name;
} StringInfo;

extern  StringInfo *string_info;
extern  unsigned char *p;
extern ssize_t i;
extern unsigned char *q;
extern unsigned char hex_digits[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < (ssize_t)string_info->length; i++) {
        for (int nibble = 0; nibble < 2; nibble++) {
            if (nibble == 0)
                *q++ = hex_digits[(p[i] >> 4) & 15];
            else
                *q++ = hex_digits[p[i] & 15];
        }
    }
}
