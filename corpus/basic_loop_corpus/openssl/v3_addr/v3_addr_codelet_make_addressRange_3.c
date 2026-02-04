#include <stdio.h>

#include <inttypes.h>

extern unsigned char *min;
extern  int length;
extern int i;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = length; i > 0 && min[i - 1] == 0; --i)
    ;

}
