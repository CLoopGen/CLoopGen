#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef enum {
    UndefinedKernel,
    UnityKernel,
    GaussianKernel,
    DoGKernel,
    LoGKernel,
    BlurKernel,
    CometKernel,
    BinomialKernel,
    LaplacianKernel,
    SobelKernel,
    FreiChenKernel,
    RobertsKernel,
    PrewittKernel,
    CompassKernel,
    KirschKernel,
    DiamondKernel,
    SquareKernel,
    RectangleKernel,
    OctagonKernel,
    DiskKernel,
    PlusKernel,
    CrossKernel,
    RingKernel,
    PeaksKernel,
    EdgesKernel,
    CornersKernel,
    DiagonalsKernel,
    LineEndsKernel,
    LineJunctionsKernel,
    RidgesKernel,
    ConvexHullKernel,
    ThinSEKernel,
    SkeletonKernel,
    ChebyshevKernel,
    ManhattanKernel,
    OctagonalKernel,
    EuclideanKernel,
    UserDefinedKernel
} KernelInfoType;

typedef double MagickDoubleType;
typedef MagickDoubleType MagickRealType;

typedef struct _KernelInfo {
    KernelInfoType type;
    size_t width;
    size_t height;
    ssize_t x;
    ssize_t y;
    MagickRealType *values;
    double minimum;
    double maximum;
    double negative_range;
    double positive_range;
    double angle;
    struct _KernelInfo *next;
    size_t signature;
} KernelInfo;

KernelInfo *kernel;
ssize_t i;
KernelInfo *new_kernel;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64 MB of data for appropriate timing (~0.01 sec on modern CPU)
    const size_t side = (size_t) sqrt(data_size);

    kernel = (KernelInfo*)calloc(1, sizeof(KernelInfo));
    new_kernel = (KernelInfo*)calloc(1, sizeof(KernelInfo));

    kernel->width = side;
    kernel->height = side;
    kernel->values = (MagickRealType*)malloc(data_size * sizeof(MagickRealType));

    new_kernel->width = side;
    new_kernel->height = side;
    new_kernel->values = (MagickRealType*)malloc(data_size * sizeof(MagickRealType));

    kernel->type = UnityKernel;
    kernel->x = 0;
    kernel->y = 0;
    kernel->minimum = 0.0;
    kernel->maximum = 1.0;
    kernel->negative_range = 0.0;
    kernel->positive_range = 1.0;
    kernel->angle = 0.0;
    kernel->next = NULL;
    kernel->signature = 0x12345678UL;

    new_kernel->type = UnityKernel;
    new_kernel->x = 0;
    new_kernel->y = 0;
    new_kernel->minimum = 0.0;
    new_kernel->maximum = 1.0;
    new_kernel->negative_range = 0.0;
    new_kernel->positive_range = 1.0;
    new_kernel->angle = 0.0;
    new_kernel->next = NULL;
    new_kernel->signature = 0x12345678UL;

    for (size_t idx = 0; idx < data_size; idx++) {
        kernel->values[idx] = (MagickRealType)(idx % 256) / 255.0;
    }
}