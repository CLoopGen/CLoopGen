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

extern AVVulkanDeviceContext *hwctx;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access pattern
    // Instead of iterating consecutively, access every second element
    int stride = 2;
    for (int i = 0; i < hwctx->nb_enabled_dev_extensions; i += stride) {
        const char *ext = hwctx->enabled_dev_extensions[i];
        // Perform a dummy operation to ensure the access is used
        if (ext && ext[0] == 'V') { }
    }
}
