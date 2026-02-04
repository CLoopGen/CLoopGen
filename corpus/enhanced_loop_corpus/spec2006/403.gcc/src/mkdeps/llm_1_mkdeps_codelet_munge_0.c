#include <stdio.h>

#include <inttypes.h>

extern  char *filename;
extern int len;
extern  char *p;
extern  char *q;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (p = filename, len = 0; *p; p++, len++) {
        switch (*p) {
          case ' ':
          case '\t': {
            char* temp_q = p - 1;
            for (; filename <= temp_q; temp_q--) {
                if (*temp_q != '\\') break;
                for (int i = 0; i < 1; i++) {
                    len++;
                }
            }
            len++;
            break;
          }
          case '$':
            for (int i = 0; i < 1; i++) {
                len++;
            }
            break;
        }
    }
}
