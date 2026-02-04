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
    int found = 0;
    for (ext = uc.query; !found && ext > uc.path; ext--)
        found = (*ext == '.');
    if (!found)
        ext = uc.path;
}
