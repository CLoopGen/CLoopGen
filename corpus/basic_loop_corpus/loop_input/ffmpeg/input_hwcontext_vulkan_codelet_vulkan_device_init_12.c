#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct AVVulkanDeviceContext {
    const int *alloc;
    int inst;
    int phys_dev;
    int act_dev;
    int queue_family_index;
    int nb_graphics_queues;
    int queue_family_tx_index;
    int nb_tx_queues;
    int queue_family_comp_index;
    int nb_comp_queues;
    const char *const *enabled_inst_extensions;
    int nb_enabled_inst_extensions;
    const char *const *enabled_dev_extensions;
    int nb_enabled_dev_extensions;
    int device_features;
} AVVulkanDeviceContext;

static const char *create_enabled_dev_extensions(int count) {
    const char **exts = malloc(count * sizeof(char *));
    for (int i = 0; i < count; i++) {
        exts[i] = "VK_EXT_placeholder";
    }
    return (const char *)exts;
}

static const char *create_enabled_inst_extensions(int count) {
    const char **exts = malloc(count * sizeof(char *));
    for (int i = 0; i < count; i++) {
        exts[i] = "VK_KHR_placeholder";
    }
    return (const char *)exts;
}

AVVulkanDeviceContext *hwctx;

void init_vars() {
    hwctx = malloc(sizeof(AVVulkanDeviceContext));
    hwctx->alloc = NULL;
    hwctx->inst = 0;
    hwctx->phys_dev = 0;
    hwctx->act_dev = 0;
    hwctx->queue_family_index = 0;
    hwctx->nb_graphics_queues = 1;
    hwctx->queue_family_tx_index = 1;
    hwctx->nb_tx_queues = 1;
    hwctx->queue_family_comp_index = 2;
    hwctx->nb_comp_queues = 1;
    hwctx->device_features = 0;

    int approx_duration_ms = 10;
    int iterations_per_ms = 100000;
    int target_iterations = approx_duration_ms * iterations_per_ms;
    hwctx->nb_enabled_dev_extensions = target_iterations > 0 ? target_iterations : 1000;

    hwctx->enabled_dev_extensions = (const char *const *)create_enabled_dev_extensions(hwctx->nb_enabled_dev_extensions);

    hwctx->nb_enabled_inst_extensions = 5;
    hwctx->enabled_inst_extensions = (const char *const *)create_enabled_inst_extensions(hwctx->nb_enabled_inst_extensions);
}