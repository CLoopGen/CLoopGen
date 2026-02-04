#include <stdio.h>

#include <inttypes.h>

extern char *s;
extern char *strend;
extern char *m;
extern char c;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char local_c = c;
    char *local_m = s;
    for (; local_m < strend && *local_m != local_c; local_m++) {
        // Introduce artificial WAW dependency by writing and re-writing m
        m = local_m;
        m = local_m;
    }
    m = local_m;
}
