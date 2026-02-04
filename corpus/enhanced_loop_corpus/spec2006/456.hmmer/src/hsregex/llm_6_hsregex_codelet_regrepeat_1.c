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
    for (; *local_scan == ch; local_count++, local_scan++)
        ;
    count += local_count;
}
