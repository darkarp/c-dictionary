# Simple dictionary in C

## Observation
- Still in development. Run `make` for a list of self-explanatory options.
- If you want to try `collisions.py`, you have to run `python3 setup.py install` to build and install the C extension used by `collisions.py`
    - Note that you **must** make sure the `Python.h` include in `calculations.c` for the module installation to succeed. On Linux all you have to do is `sudo apt install python3-dev`. On Windows, you must find the `Python.h` file in the installation directory and change the include manually to point to it.

## TODO
    * Documentation
    * Utility functions
    * Stability check
    * Multiple hash support
    * File & membuffer I/O for saving/loading
