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
    unsigned char *s = in->text;
    unsigned char *lim = s + in->len;
    unsigned char *d = (unsigned char *)dest;
    for (; s < lim; ) {
        unsigned char c = *s;
        if (c == '\\' && (s + 1 < lim) && (s[1] == '\\' || s[1] == '"')) {
            *d++ = c;
            s++;
        }
        *d++ = *s++;
    }
    dest = (char *)d;
}
