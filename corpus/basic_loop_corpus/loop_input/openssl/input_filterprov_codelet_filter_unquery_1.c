#include <stdio.h>
#include <inttypes.h>

struct ossl_dispatch_st {
    int function_id;
    void (*function)();
};

typedef struct ossl_dispatch_st OSSL_DISPATCH;

struct ossl_algorithm_st {
    const char *algorithm_names;
    const char *property_definition;
    const OSSL_DISPATCH *implementation;
    const char *algorithm_description;
};

typedef struct ossl_algorithm_st OSSL_ALGORITHM;

typedef struct ossl_lib_ctx_st OSSL_LIB_CTX;

typedef struct ossl_provider_st OSSL_PROVIDER;

struct filter_prov_globals_st {
    OSSL_LIB_CTX *libctx;
    OSSL_PROVIDER *deflt;
    struct {
        int operation;
        OSSL_ALGORITHM alg[6];
    } dispatch[10];
    int num_dispatch;
    int no_cache;
    unsigned long query_count;
    int error;
};

static OSSL_ALGORITHM static_algs[10 * 6]; 
static struct filter_prov_globals_st static_globs;
static int static_i;

OSSL_ALGORITHM *algs = static_algs;
struct filter_prov_globals_st *globs = &static_globs;
int i = 0;

void init_vars() {
    for (int idx = 0; idx < 10 * 6; idx++) {
        static_algs[idx].algorithm_names = "test";
        static_algs[idx].property_definition = "prop";
        static_algs[idx].implementation = NULL;
        static_algs[idx].algorithm_description = "desc";
    }

    static_globs.libctx = NULL;
    static_globs.deflt = NULL;
    static_globs.num_dispatch = 10;
    static_globs.no_cache = 0;
    static_globs.query_count = 0;
    static_globs.error = 0;

    for (int d = 0; d < 10; d++) {
        static_globs.dispatch[d].operation = d;
        for (int a = 0; a < 6; a++) {
            static_globs.dispatch[d].alg[a].algorithm_names = "test";
            static_globs.dispatch[d].alg[a].property_definition = "prop";
            static_globs.dispatch[d].alg[a].implementation = NULL;
            static_globs.dispatch[d].alg[a].algorithm_description = "desc";
        }
    }

    for (volatile int j = 0; j < 80000; j++) {
        __asm__ volatile("");
    }
}