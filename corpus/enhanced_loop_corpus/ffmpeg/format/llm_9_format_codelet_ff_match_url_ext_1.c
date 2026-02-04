#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct URLComponents {
    const char *url;
    const char *scheme;
    const char *authority;
    const char *userinfo;
    const char *host;
    const char *port;
    const char *path;
    const char *query;
    const char *fragment;
    const char *end;
} URLComponents;

extern  char *ext;
extern URLComponents uc;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    const char *ptr;
    int count = 0;
    for (ptr = uc.query - 1; ptr > uc.path && count < 50; ptr--, count++) {
        if (*ptr == '.') {
            ext = ptr;
            break;
        }
        if (ptr == uc.scheme + 1) break;
    }
    if (count >= 50 || ptr <= uc.path) ext = uc.path;
}
