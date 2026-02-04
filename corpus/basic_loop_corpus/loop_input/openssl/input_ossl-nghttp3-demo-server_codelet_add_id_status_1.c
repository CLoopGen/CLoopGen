#include <stdint.h>
#include <string.h>

typedef struct ssl_st SSL;

struct ssl_id {
    SSL *s;
    uint64_t id;
    int status;
};

uint64_t id = 0x123456789ABCDEF0ULL;
SSL *ssl = (SSL *)0x1000;
int status = 1;
int i;

struct ssl_id *ssl_ids;

void init_vars() {
    const int size = 256 * 1024 / sizeof(struct ssl_id); // ~256KB of data
    ssl_ids = __builtin_malloc(size * sizeof(struct ssl_id));
    memset(ssl_ids, 0, size * sizeof(struct ssl_id));
}