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
    char *local_scan = ep->reginput;
    size_t local_count = 0;
    for (; *local_scan == ch && *(local_scan + 1) == ch; local_scan += 2)
        local_count += 2;
    if (*local_scan == ch)
        local_count++;
    count += local_count;
}
