#include <stdio.h>

#include <inttypes.h>

extern char *p;
extern int n;
extern char *q;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (q--; p < q; p++ , q--) {
    n = *p;
    *p = *q;
    *q = n;
}

}
