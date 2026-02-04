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
    // Variant 2: Indirect memory access via index array (simulated with pointer arithmetic)
    size_t i;
    size_t len = 0;
    char* ptr = path;
    // First, compute effective length (excluding '\0')
    while (ptr[len] != '\0') len++;

    // Use an index array to access characters indirectly in reverse order
    for (i = 0; i < len; i++) {
        char c = path[len - 1 - i]; // Reverse access pattern
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
