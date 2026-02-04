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
    unsigned char *local_src = src;
    unsigned char *local_limit = limit;
    char *local_dest = dest;
    cpp_string *local_in = in;

    for (local_src = local_in->text, local_limit = local_src + local_in->len; 
         local_src < local_limit; ) {
        unsigned char c = *local_src;
        if (c == '\\' && (local_src[1] == '\\' || local_src[1] == '"')) {
            local_src++;
        }
        *local_dest++ = *local_src++;
    }

    src = local_src;
    dest = local_dest;
}
