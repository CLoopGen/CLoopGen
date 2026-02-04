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
    size_t stride = 1;
    size_t local_count = 0;
    for (int i = 0; i < 1 && local_scan != NULL && *local_scan == ch; i++) {
        while (*(local_scan + stride - 1) == ch) {
            local_scan += stride;
            local_count += stride;
            stride = (stride < 8) ? stride + 1 : stride;
        }
    }
    count += local_count;
}
