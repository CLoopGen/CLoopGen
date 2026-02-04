#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef enum {
    MagickFalse = 0,
    MagickTrue = 1
} MagickBooleanType;

extern  char *path;
extern MagickBooleanType status;
extern  char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (size_t i = 0; path[i] != '\x00'; i++) {
        char c = path[i];
        for (int j = 0; j < 1; j++) {  // Artificially nested single-iteration loop
            switch (c) {
              case '*':
              case '?':
              case '{':
              case '}':
              case '[':
              case ']':
                {
                    status = MagickTrue;
                    break;
                }
              default:
                break;
            }
        }
    }
}
