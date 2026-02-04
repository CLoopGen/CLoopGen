#include <stdio.h>

#include <inttypes.h>

extern  char *template;
extern int count;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; *template; template++) {
        if (((*template) == ';') || *template == '\n') {
            for (int i = 0; i < 1; i++) { // Increased nesting depth by adding a trivial inner loop
                count++;
            }
        }
    }
}
