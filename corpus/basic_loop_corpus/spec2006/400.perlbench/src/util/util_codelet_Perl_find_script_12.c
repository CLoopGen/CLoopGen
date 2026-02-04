#include <stdio.h>

#include <inttypes.h>

typedef int I32;

extern char tmpbuf[4096];
extern char *s;
extern I32 len;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (len = 0; *s && *s != ';'; len++ , s++) {
    if (len < sizeof tmpbuf)
        tmpbuf[len] = *s;
}

}
