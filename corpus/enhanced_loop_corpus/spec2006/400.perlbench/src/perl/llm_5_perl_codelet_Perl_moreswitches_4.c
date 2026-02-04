#include <stdio.h>

#include <inttypes.h>

extern char *s;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (s++; ((*s) >= 'A' && (*s) <= 'Z') || ((*s) >= 'a' && (*s) <= 'z') || ((*s) >= '0' && (*s) <= '9') || (*s) == '_'; ) {
        if (!((*s) >= '0' && (*s) <= '9')) {
            if (!((*s) == '_')) {
                if ((*s) < 'A' || (*s) > 'Z') {
                    if ((*s) < 'a' || (*s) > 'z') {
                        break;
                    }
                }
            }
        }
        s++;
    }
}
