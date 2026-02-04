#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

char *ext;
URLComponents uc;

void init_vars() {
    size_t data_size = 16 * 1024 * 1024; // 16 MB to target ~0.01 sec runtime
    char *data = (char *)malloc(data_size);
    if (!data) {
        exit(1);
    }

    // Initialize data with non-dot characters except near the expected traversal range
    memset(data, 'x', data_size);

    // Place a '.' near the beginning of what will be the query section
    data[data_size - 1] = '.';

    // Set up URL components
    uc.url = data;
    uc.scheme = data;
    uc.authority = data;
    uc.userinfo = data;
    uc.host = data;
    uc.port = data;
    uc.path = data;
    uc.query = data + data_size - 2;  // Point near end, before the '.'
    uc.fragment = data + data_size - 1;
    uc.end = data + data_size;

    ext = uc.query;

    // Ensure loop condition: *ext != '.' and ext > uc.path holds initially
    // so that we enter the loop and walk backward until hitting '.'
}