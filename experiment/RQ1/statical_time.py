import json
import os
import argparse
import csv
import subprocess
import tempfile

TIME_OUT = 30

def compile_and_run(loop_file, input_file, driver, corpus_dir):

    with tempfile.TemporaryDirectory() as tmpdir:
        exec_file = os.path.join(tmpdir, "a.out")
        try:
            result = subprocess.run(
                ["clang", "-O3",
                loop_file, input_file, driver, "-o", exec_file, "-lm"],
                cwd=corpus_dir,
                capture_output=True,
                text=True,
                timeout=TIME_OUT
            )
            if result.returncode == 0:
                # print(f"Successfully compiled {loop_file}")
                run_result = subprocess.run(
                    ["numactl", "-m", "0", "--physcpubind", "0", exec_file],
                    cwd=tmpdir,
                    capture_output=True,
                    text=True,
                    timeout=TIME_OUT
                )
                if run_result.returncode == 0:
                    return True, run_result.stdout
                else:
                    if run_result.returncode < 0:
                        import signal
                        signal_name = signal.Signals(-run_result.returncode).name
                        return False, f"Program terminated by signal: {signal_name}"
                    else:
                        return False, f"Run failed with exit code {run_result.returncode}:\n{run_result.stderr}\n{run_result.stdout}"
            else:
                return False, result.stderr + result.stdout
        except subprocess.TimeoutExpired:
            return False, "Compilation or run timed out."
        except FileNotFoundError:
            raise RuntimeError("clang not found. Please install Clang.")

def statical_time_distribution(programs, corpus_dir, driver_path, json_dir, result_csv):
    lt1us_count = 0
    lt1ms_count = 0
    lt1s_count = 0
    gt1s_count = 0

    for program in programs:
        json_file = os.path.join(json_dir, f"{program}.json")
        with open(json_file, 'r') as f:
            loops = json.load(f)
        
        for loop in loops:
            loop_file = loop.get("codelet")
            input_file = loop.get("input")
            flag, time = compile_and_run(loop_file, input_file, driver_path, corpus_dir)
            if not flag:
                continue
            time = int(time.strip())
            if time == 0:
                lt1us_count += 1
            elif time < 1000:
                lt1ms_count += 1
            elif time < 1000000:
                lt1s_count += 1
            else:
                gt1s_count += 1

    with open(result_csv, 'w', newline='') as csvfile:
        csvwriter = csv.writer(csvfile)
        csvwriter.writerow(["Time Range", "Count"])
        csvwriter.writerow(["<1us", lt1us_count])
        csvwriter.writerow(["1us-1ms", lt1ms_count])
        csvwriter.writerow(["1ms-1s", lt1s_count])
        csvwriter.writerow([">1s", gt1s_count])

    # print(f"Time Distribution:")
    # print(f"<1us: {lt1us_count}")
    # print(f"1us-1ms: {lt1ms_count}")
    # print(f"1ms-1s: {lt1s_count}")
    # print(f">1s: {gt1s_count}")

if __name__ == "__main__":
    programs = ["polybench", "npb", "tsvc", "rodinia", "cbench", "spec2006", "opencv", "openssl", "openblas", "gsl", "ImageMagick", "redis", "numpy", "fftw", "ffmpeg"]
    # programs = ["polybench"]
    corpus_dir = "../../corpus"
    driver_path = "driver/main.c"
    json_dir = "../../corpus/basic_json"
    result_csv = "statical_basic_time.csv"

    statical_time_distribution(programs, corpus_dir, driver_path, json_dir, result_csv)

    json_dir = "../../corpus/enhanced_json"
    result_csv = "statical_enhanced_time.csv"
    statical_time_distribution(programs, corpus_dir, driver_path, json_dir, result_csv)
