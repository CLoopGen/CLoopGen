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



void loop() {
    // Variant 1: Strided memory access (step by 2 backward from uc.query to uc.path)
    ptrdiff_t diff = uc.query - uc.path;
    for (ext = uc.query - (diff % 2); diff > 0; ext -= 2, diff -= 2) {
        if (*ext == '.') break;
    }
}
