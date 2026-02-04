#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

enum rtx_code {
    UNKNOWN,
    NIL,
    INCLUDE,
    EXPR_LIST,
    INSN_LIST,
    MATCH_OPERAND,
    MATCH_SCRATCH,
    MATCH_DUP,
    MATCH_OPERATOR,
    MATCH_PARALLEL,
    MATCH_OP_DUP,
    MATCH_PAR_DUP,
    MATCH_INSN,
    DEFINE_INSN,
    DEFINE_PEEPHOLE,
    DEFINE_SPLIT,
    DEFINE_INSN_AND_SPLIT,
    DEFINE_PEEPHOLE2,
    DEFINE_COMBINE,
    DEFINE_EXPAND,
    DEFINE_DELAY,
    DEFINE_FUNCTION_UNIT,
    DEFINE_ASM_ATTRIBUTES,
    DEFINE_COND_EXEC,
    SEQUENCE,
    ADDRESS,
    DEFINE_ATTR,
    ATTR,
    SET_ATTR,
    SET_ATTR_ALTERNATIVE,
    EQ_ATTR,
    ATTR_FLAG,
    INSN,
    JUMP_INSN,
    CALL_INSN,
    BARRIER,
    CODE_LABEL,
    NOTE,
    COND_EXEC,
    PARALLEL,
    ASM_INPUT,
    ASM_OPERANDS,
    UNSPEC,
    UNSPEC_VOLATILE,
    ADDR_VEC,
    ADDR_DIFF_VEC,
    PREFETCH,
    SET,
    USE,
    CLOBBER,
    CALL,
    RETURN,
    TRAP_IF,
    RESX,
    CONST_INT,
    CONST_DOUBLE,
    CONST_VECTOR,
    CONST_STRING,
    CONST,
    PC,
    VALUE,
    REG,
    SCRATCH,
    SUBREG,
    STRICT_LOW_PART,
    CONCAT,
    MEM,
    LABEL_REF,
    SYMBOL_REF,
    CC0,
    ADDRESSOF,
    QUEUED,
    IF_THEN_ELSE,
    COND,
    COMPARE,
    PLUS,
    MINUS,
    NEG,
    MULT,
    DIV,
    MOD,
    UDIV,
    UMOD,
    AND,
    IOR,
    XOR,
    NOT,
    ASHIFT,
    ROTATE,
    ASHIFTRT,
    LSHIFTRT,
    ROTATERT,
    SMIN,
    SMAX,
    UMIN,
    UMAX,
    PRE_DEC,
    PRE_INC,
    POST_DEC,
    POST_INC,
    PRE_MODIFY,
    POST_MODIFY,
    NE,
    EQ,
    GE,
    GT,
    LE,
    LT,
    GEU,
    GTU,
    LEU,
    LTU,
    UNORDERED,
    ORDERED,
    UNEQ,
    UNGE,
    UNGT,
    UNLE,
    UNLT,
    LTGT,
    SIGN_EXTEND,
    ZERO_EXTEND,
    TRUNCATE,
    FLOAT_EXTEND,
    FLOAT_TRUNCATE,
    FLOAT,
    FIX,
    UNSIGNED_FLOAT,
    UNSIGNED_FIX,
    ABS,
    SQRT,
    FFS,
    SIGN_EXTRACT,
    ZERO_EXTRACT,
    HIGH,
    LO_SUM,
    RANGE_INFO,
    RANGE_REG,
    RANGE_VAR,
    RANGE_LIVE,
    CONSTANT_P_RTX,
    CALL_PLACEHOLDER,
    VEC_MERGE,
    VEC_SELECT,
    VEC_CONCAT,
    VEC_DUPLICATE,
    SS_PLUS,
    US_PLUS,
    SS_MINUS,
    US_MINUS,
    SS_TRUNCATE,
    US_TRUNCATE,
    PHI,
    LAST_AND_UNUSED_RTX_CODE
};

enum machine_mode {
    VOIDmode,
    BImode,
    QImode,
    HImode,
    SImode,
    DImode,
    TImode,
    OImode,
    PQImode,
    PHImode,
    PSImode,
    PDImode,
    QFmode,
    HFmode,
    TQFmode,
    SFmode,
    DFmode,
    XFmode,
    TFmode,
    QCmode,
    HCmode,
    SCmode,
    DCmode,
    XCmode,
    TCmode,
    CQImode,
    CHImode,
    CSImode,
    CDImode,
    CTImode,
    COImode,
    V2QImode,
    V2HImode,
    V2SImode,
    V2DImode,
    V4QImode,
    V4HImode,
    V4SImode,
    V4DImode,
    V8QImode,
    V8HImode,
    V8SImode,
    V8DImode,
    V16QImode,
    V2SFmode,
    V2DFmode,
    V4SFmode,
    V4DFmode,
    V8SFmode,
    V8DFmode,
    V16SFmode,
    BLKmode,
    CCmode,
    CCGCmode,
    CCGOCmode,
    CCNOmode,
    CCZmode,
    CCFPmode,
    CCFPUmode,
    MAX_MACHINE_MODE
};

typedef struct rtx_def *rtx;

struct rtvec_def {
    int num_elem;
    rtx elem[1];
};

typedef struct rtvec_def *rtvec;

typedef struct {
    unsigned int min_align : 8;
    unsigned int base_after_vec : 1;
    unsigned int min_after_vec : 1;
    unsigned int max_after_vec : 1;
    unsigned int min_after_base : 1;
    unsigned int max_after_base : 1;
    unsigned int offset_unsigned : 1;
    unsigned int : 2;
    unsigned int scale : 8;
} addr_diff_vec_flags;

typedef union tree_node *tree;

typedef struct {
    long alias;
    tree expr;
    rtx offset;
    rtx size;
    unsigned int align;
} mem_attrs;

typedef union rtunion_def {
    long rtwint;
    int rtint;
    unsigned int rtuint;
    const char *rtstr;
    rtx rtx;
    rtvec rtvec;
    enum machine_mode rttype;
    addr_diff_vec_flags rt_addr_diff_vec_flags;
    struct cselib_val_struct *rt_cselib;
    struct bitmap_head_def *rtbit;
    tree rttree;
    struct basic_block_def *bb;
    mem_attrs *rtmem;
} rtunion;

struct rtx_def {
    enum rtx_code code : 16;
    enum machine_mode mode : 8;
    unsigned int jump : 1;
    unsigned int call : 1;
    unsigned int unchanging : 1;
    unsigned int volatil : 1;
    unsigned int in_struct : 1;
    unsigned int used : 1;
    unsigned int integrated : 1;
    unsigned int frame_related : 1;
    rtunion fld[1];
};

enum op_type {
    OP_IN,
    OP_OUT,
    OP_INOUT
};

struct recog_data {
    rtx operand[30];
    rtx *operand_loc[30];
    const char *constraints[30];
    enum machine_mode operand_mode[30];
    enum op_type operand_type[30];
    rtx *dup_loc[4];
    char dup_num[4];
    char n_operands;
    char n_dups;
    char n_alternatives;
    rtx insn;
};

struct recog_data recog_data;
int i;
int commutative;

static struct rtx_def dummy_rtx_pool[128];
static rtx *dummy_operand_pool;
static rtx **dummy_dup_loc_pool;

void init_vars() {
    memset(&recog_data, 0, sizeof(recog_data));
    
    const int pool_size = 128;
    memset(dummy_rtx_pool, 0, sizeof(dummy_rtx_pool));
    for (int idx = 0; idx < pool_size; idx++) {
        dummy_rtx_pool[idx].code = CONST_INT;
        dummy_rtx_pool[idx].mode = SImode;
        dummy_rtx_pool[idx].fld[0].rtint = idx;
    }
    
    dummy_operand_pool = (rtx*)calloc(30, sizeof(rtx));
    for (int j = 0; j < 30; j++) {
        dummy_operand_pool[j] = &dummy_rtx_pool[j % pool_size];
    }
    
    memcpy(recog_data.operand, dummy_operand_pool, sizeof(rtx) * 30);
    
    for (int j = 0; j < 30; j++) {
        recog_data.operand_loc[j] = &recog_data.operand[j];
        recog_data.constraints[j] = "";
        recog_data.operand_mode[j] = SImode;
        recog_data.operand_type[j] = OP_IN;
    }
    
    dummy_dup_loc_pool = (rtx**)calloc(4, sizeof(rtx*));
    for (int j = 0; j < 4; j++) {
        dummy_dup_loc_pool[j] = &recog_data.operand[j];
    }
    
    memcpy(recog_data.dup_loc, dummy_dup_loc_pool, sizeof(rtx*) * 4);
    
    recog_data.n_operands = 30;
    recog_data.n_dups = 4;
    recog_data.n_alternatives = 2;
    recog_data.insn = &dummy_rtx_pool[0];
    
    commutative = 2;
    
    for (int j = 0; j < 4; j++) {
        recog_data.dup_num[j] = j + commutative - 1;
    }
}