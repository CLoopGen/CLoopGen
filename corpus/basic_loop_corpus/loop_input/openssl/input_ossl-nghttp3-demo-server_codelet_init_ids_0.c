#include <stdint.h>

typedef struct ssl_st SSL;

struct ssl_id {
    SSL *s;
    uint64_t id;
    int status;
};

struct ssl_id *ssl_ids;
int i;

void init_vars() {
    static struct ssl_id ssl_ids_storage[1024];
    ssl_ids = ssl_ids_storage;
}