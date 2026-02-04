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
    // Variant 2: Consecutive access using array indexing with explicit pointer arithmetic as base
    const char *base = uc.path;
    size_t len = uc.query - uc.path;
    for (size_t i = len; i > 0; --i) {
        ext = base + i - 1;
        if (*ext == '.') break;
    }
}
