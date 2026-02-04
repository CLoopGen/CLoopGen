#include <stdio.h>

#include <inttypes.h>

struct exec {
    char *reginput;
    char *regbol;
    char **regstartp;
    char **regendp;
};


extern struct exec *ep;
extern size_t count;
extern char *scan;
extern char ch;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (scan = ep->reginput; *scan == ch; scan++) {
        if (*scan == ch) {
            count++;
        } else {
            break;
        }
    }
}
