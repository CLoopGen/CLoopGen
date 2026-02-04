#include <stdio.h>

#include <inttypes.h>

extern char *name;
extern char *p;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (; p - name > 2; p--)
    *p = *(p - 1);

}
