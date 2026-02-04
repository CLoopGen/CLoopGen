#include <stdio.h>

#include <inttypes.h>

struct cpp_string {
    unsigned int len;
    const unsigned char *text;
};


typedef struct cpp_string cpp_string;

extern  cpp_string *in;
extern  unsigned char *src;
extern  unsigned char *limit;
extern char *dest;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (src = in->text, limit = src + in->len; src < limit; ) {
        if (*src == '\\' && (src[1] == '\\' || src[1] == '"')) {
            *dest++ = *src++;
            src++; // Skip the escape character's target
            continue;
        }
        *dest++ = *src++;
    }
}
