import os
MKFILE_FILENAME = "Makefile"
MKFILE_TEMPLATE_DIR = "templates"
MKFILE_TEMPLATE_FILENAME = f"{MKFILE_TEMPLATE_DIR}/"

if os.name == "nt":
    MKFILE_TEMPLATE_FILENAME += "Makefile_nt"
    EXECUTE_STR = "nmake all"

elif os.name == "posix":
    MKFILE_TEMPLATE_FILENAME += "Makefile_posix"
    HELP_STR = "make help"
    EXECUTE_STR = "make all"


def read_file(filename: str) -> str:
    with open(filename, "r") as f:
        data = f.read()
    return data


def write_file(data: str, filename: str = MKFILE_FILENAME) -> int:
    with open(filename, "w") as f:
        return f.write(data)


def gen_makefile():
    data = read_file(MKFILE_TEMPLATE_FILENAME)
    written = write_file(data)
    print(f"[+] Wrote {written} bytes to {MKFILE_FILENAME}")


if __name__ == "__main__":
    gen_makefile()
