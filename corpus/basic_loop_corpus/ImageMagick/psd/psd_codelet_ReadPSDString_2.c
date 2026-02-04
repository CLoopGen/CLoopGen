#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *p;
extern char *q;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (--q; p < q; ++p , --q) {
    *p = *p ^ *q , *q = *p ^ *q , *p = *p ^ *q;
}

}
