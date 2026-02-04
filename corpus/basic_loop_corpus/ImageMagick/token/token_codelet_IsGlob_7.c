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
for (p = path; *p != '\x00'; p++) {
    switch (*p) {
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
