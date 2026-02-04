#include <stdio.h>

#include <inttypes.h>

extern char *p;
extern char *r;
extern size_t l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *local_p = p;
    char *local_r = r;
    size_t local_l = l;
    for (; *local_p; local_p++) {
        if (*local_p == '^' && local_p[1] != '\x00') {
            local_p++;
        } else if (*local_p == ':' || *local_p == '>' || *local_p == ']') {
            local_l -= local_p + 1 - local_r;
            local_r = local_p + 1;
        } else if (*local_p == ';') {
            local_l = local_p - local_r;
            break;
        }
    }
    p = local_p;
    r = local_r;
    l = local_l;
}
