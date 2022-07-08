# Simple dictionary in C

## Observation
- Still in development. Run `make` for a list of self-explanatory options.
- This isn't required to work with the dict, but if you want to try `collisions.py`, you have to run `python3 setup.py install` to build and install the C extension used by `collisions.py`. This python script only shows you the collision rate for even, odd and prime dict sizes, for educational purposes.
    - Note that you **must** make sure the `Python.h` include in `calculations.c` for the module installation to succeed. On Linux all you have to do is `sudo apt install python3-dev`. On Windows, you must find the `Python.h` file in the installation directory and change the include manually to point to it.

## TODO
    * Documentation
    * Utility functions
    * Stability check
    * Multiple hash support
    * File & membuffer I/O for saving/loading
