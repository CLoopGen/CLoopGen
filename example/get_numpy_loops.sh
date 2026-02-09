#!/bin/bash

git clone https://github.com/numpy/numpy.git --depth 1
mkdir numpy_loops
PYTHON_INCLUDE=$(python3-config --includes 2>/dev/null)
bash ../scripts/loop_extractor.sh ../build/loopExtractor ./numpy ./numpy_loops  "-I./numpy -I./numpy/numpy/linalg/lapack_lite $PYTHON_INCLUDE  -I./numpy/numpy/_core/include -I./numpy/numpy/_core/src/common" "-DNPY_BITSOF_SHORT=16  -DNPY_BITSOF_INT=32 -DNPY_BITSOF_LONG=64 -DNPY_BITSOF_LONGLONG=64"
bash ../scripts/get_loops_list.sh ./numpy_loops ./numpy_loop_list.txt
python3 ../scripts/gen_input.py --main_file ../corpus/driver/main.c --loopset_file ./numpy_loop_list.txt --output_dir ./loop_input/numpy --output numpy_basic_corpus.json --fail_loops_file ./numpy_init_fail.txt --max_retries 5 --api_key sk-49345453dd3b41e7a463b60900bf9fda --base_url https://dashscope.aliyuncs.com/compatible-mode/v1 --model_name qwen-plus
python3 ../scripts/enhance_corpus.py --loop_record numpy_basic_corpus.json --program_name numpy --llm_loop_record numpy_enhanced_corpus.txt --N 5 --api_key sk-49345453dd3b41e7a463b60900bf9fda --base_url https://dashscope.aliyuncs.com/compatible-mode/v1 --model_name qwen-plus
python3 ../scripts/filter_enhance.py --input_loop_record numpy_enhanced_corpus.txt --output_loop_record numpy_enhanced_corpus.json --driver ../corpus/driver/main.c
