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

struct {
    int operation;
    OSSL_ALGORITHM alg[6];
};


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


extern  OSSL_ALGORITHM *algs;
extern struct filter_prov_globals_st *globs;
extern int i;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i < globs->num_dispatch; i++)
    if (globs->dispatch[i].alg == algs)
        return;

}
