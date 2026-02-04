#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int j;
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = 0;
    for (i = 0; i < j; i++) {
        temp = i;  // Introduce temporary variable creating WAW dependency on 'i'
        if (p[temp] == '\n') {
            i = temp + 1;  // Update 'i' with dependency on temp (WAW and RAW introduced)
            break;
        }
    }
}
