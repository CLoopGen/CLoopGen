import argparse
import os
import sys
import subprocess
import json
import tempfile
from concurrent.futures import ThreadPoolExecutor, as_completed
import numpy as np


def exec_command(cmd):
    try:
        result = subprocess.run(
            cmd,
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            text=True,
            check=True
        )
        return result.stdout, True
    except (subprocess.CalledProcessError, FileNotFoundError) as e:
        error_msg = ""
        if isinstance(e, subprocess.CalledProcessError):
            error_msg = f"Command failed: {' '.join(cmd)}\nReturn code: {e.returncode}\nSTDERR: {e.stderr}"
        else:
            error_msg = f"Executable not found: {cmd[0]}"
        print(error_msg, file=sys.stderr)
        return None, False


def extract_loop_ast_features(ast_exec, loop_file):
    cmd = [ast_exec, loop_file, "--", "-x", "c"]
    output, success = exec_command(cmd)
    if not success or output is None:
        return None

    lines = output.strip().split('\n')
    features = []
    for line in lines:
        if not line.strip():
            continue
        int_features = [int(i) for i in line.split(',')]
        assert len(int_features) == 9, f"AST feature length mismatch: expected 9, got {len(int_features)} in file {loop_file}"
        features.append(int_features)
    
    return features


def extract_loop_ir_features(pass_path, loop_file):
    with tempfile.TemporaryDirectory() as tmpdir:
        file_name = os.path.basename(loop_file)
        ir_name = file_name.rsplit('.', 1)[0] + ".ll"
        ir_path = os.path.join(tmpdir, ir_name)
        ir_opt_path = os.path.join(tmpdir, file_name + "_opt.ll")
        
        cmd = [
            "clang",
            "-Xclang", "-disable-O0-optnone",
            "-O1", "-emit-llvm", "-S",
            "-o", ir_path,
            loop_file
        ]
        _, success = exec_command(cmd)
        if not success:
            return None

        cmd = [
            "opt",
            f"-load-pass-plugin={pass_path}",
            "-passes=mem2reg,simplifycfg,loop-simplify,lcssa,indvars,ir-loop-feature",
            "-S", ir_path,
            "-o", ir_opt_path
        ]
        output, success = exec_command(cmd)
        if not success or output is None:
            return None

        lines = output.strip().split('\n')
        features = []
        for line in lines:
            if not line.strip():
                continue
            int_features = [int(i) for i in line.split(',')]
            assert len(int_features) == 13, f"IR feature length mismatch: expected 13, got {len(int_features)} in file {loop_file}"
            features.append(int_features)
        return features


def process_single_loop(loop, ast_exec, pass_path, corpus_dir):
    loop_file = loop.get("codelet")
    loop_file = os.path.join(corpus_dir, loop_file)
    if not loop_file or not os.path.isfile(loop_file):
        print(f"Loop file not found: {loop_file}", file=sys.stderr)
        return None

    ast_features = extract_loop_ast_features(ast_exec, loop_file)
    if ast_features is None:
        print(f"Failed to extract AST features for {loop_file}", file=sys.stderr)
        return None

    ir_features = extract_loop_ir_features(pass_path, loop_file)

    if ir_features is None:
        print(f"Failed to extract IR features for {loop_file}", file=sys.stderr)
        return None

    return {
        "codelet": loop_file,
        "ast_features": ast_features,
        "ir_features": ir_features
    }

def save_features_to_npy(loopsets, output_npy_file):
    features = []
    for loopset in loopsets:
        ast_features = loopset.get("ast_features")
        ir_features = loopset.get("ir_features")
        if ir_features is None:
            continue
        if len(ast_features) == len(ir_features):
            for i in range(len(ast_features)):
                all_features = ast_features[i] + ir_features[i]
                features.append(all_features)
                assert len(all_features) == 22, f"Feature length mismatch: expected 22, got {len(all_features)}"

        elif len(ir_features) == 1:
            if len(ast_features) < 1:
                continue
            all_features = ast_features[0]
            for i in range(1,len(ast_features)):
                all_features[0] = max(all_features[0], ast_features[i][0])
                for j in range(1, len(all_features)):
                    all_features[j] = all_features[j] + ast_features[i][j]
            all_features.extend(ir_features[0])
            assert len(all_features) == 22, f"Feature length mismatch: expected 22, got {len(all_features)}"
            features.append(all_features)
        else:

            continue
    feature_array = np.array(features)
    np.save(output_npy_file, feature_array)

def main():
    parser = argparse.ArgumentParser(description="Extract loop features from loop files (parallel version).")
    parser.add_argument("--astExec", type=str, required=True, help="AST-based loop features extraction executable.")
    parser.add_argument("--pass_path", type=str, required=True, help="Pass .so file path.")
    parser.add_argument("--output", type=str, required=True, help="Output JSON file path.")
    parser.add_argument("--input", type=str, required=True, help="Input JSON file containing list of loops.")
    parser.add_argument("--corpus_dir", type=str, default="../../corpus", help="Corpus directory.")
    parser.add_argument("--workers", type=int, default=1, help="Number of parallel workers (default: 1).")
    args = parser.parse_args()

    # Load input
    with open(args.input, 'r') as f:
        loopsets = json.load(f)

    featureset = []

    # Parallel processing
    with ThreadPoolExecutor(max_workers=args.workers) as executor:
        future_to_loop = {
            executor.submit(process_single_loop, loop, args.astExec, args.pass_path, args.corpus_dir): loop
            for loop in loopsets
        }

        for future in as_completed(future_to_loop):
            result = future.result()
            if result is not None:
                featureset.append(result)
    
    save_features_to_npy(featureset, args.output)




if __name__ == "__main__":
    main()
