from distutils.core import setup, Extension


def main():
    setup(name="calculations",
          version="1.0.0",
          description="Number calculations",
          author="Mario Nascimento",
          author_email="mario@whitehathacking.tech",
          ext_modules=[Extension("calculations", ["calculations.c", "dict/dict.c", "dict/node.c", "dict/hashutils.c", "dict/prime.c"])])


if __name__ == "__main__":
    main()
