from setuptools import Extension, setup
import sys
import os

if os.name == "nt":
    STAT_DIR = "/".join(__file__.split("\\")[:-1])
    PY_DIR = "\\".join(sys.executable.split("\\")[:-1])
    INCLUDE_DIR = f"{PY_DIR}/include"
    PYTHON_H_STR = f'"{INCLUDE_DIR}/Python.h"'
elif os.name == "posix":
    STAT_DIR = "/".join(__file__.split("/")[:-1])
    PYTHON_H_STR = '<Python.h>'

LIB_DIR = f"{STAT_DIR}/../dict"
CALCULATIONS_TEMPLATE_NAME = f"{STAT_DIR}/calculations.c.temp"
CALCULATIONS_NAME = f"{STAT_DIR}/calculations.c"


def gen_calculations():
    with open(CALCULATIONS_TEMPLATE_NAME, "r") as f:
        data = f.read()
    new_data = f"#include {PYTHON_H_STR}\n{data}"
    with open(CALCULATIONS_NAME, "w") as f:
        f.write(new_data)


def main():
    setup(name="calculations",
          version="1.0.0",
          description="Number calculations",
          author="Mario Nascimento",
          author_email="mario@whitehathacking.tech",
          ext_modules=[Extension("calculations", [f"{STAT_DIR}/calculations.c", f"{LIB_DIR}/dict.c", f"{LIB_DIR}/node.c", f"{LIB_DIR}/hashutils.c", f"{LIB_DIR}/prime.c"])])


if __name__ == "__main__":
    gen_calculations()
    main()
