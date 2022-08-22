# Simple dictionary in C

<p align="center">	
    <img src="https://img.shields.io/maintenance/yes/2022" />
    <a href="https://github.com/darkarp/c-dictionary/commits/master">
    <img src="https://img.shields.io/github/last-commit/darkarp/c-dictionary" />
  </a>
  <a href="https://github.com/darkarp/c-dictionary/issues?q=is%3Aopen+is%3Aissue">
	<img alt="GitHub issues" src="https://img.shields.io/github/issues/darkarp/c-dictionary" />
</a>
	<br>
  <img src="https://img.shields.io/badge/Platform-Windows%20%7C%20MacOS%20%7C%20Linux-green" />
  </br>
  <a href="https://discord.gg/beczNYP">
    <img src="https://img.shields.io/badge/discord-join-7289DA.svg?logo=discord&longCache=true&style=flat" />
  </a>
<a href="https://twitch.tv/infosecguy">
	<img alt="Twitch Status" src="https://img.shields.io/twitch/status/infosecguy?style=flat">
</a>
</br>
<a href="https://www.whitehathacking.tech">
	<img alt="Twitch Status" src="https://img.shields.io/badge/Website-visit-blue">
</a>
</p>

<!-- TABLE OF CONTENTS -->
## Table of Contents

* [About the Project](#about-the-project)  
* [Getting started](#getting-started)
  * [Requirements](#requirements)
  * [Usage](#usage)
* [Statistics Module (*optional*)](#statistics-module-optional)
* [TODO](#todo)
* [Learn More](#learn-more)
* [License](#license)
---
## About the project  
This is an implementation and usage example of a dictionary in C.  
It supports:
  * Hashing
  * Collisions (keys must be different)
  * String-like keys
  * Some utility functions as shown in `src/main.c`

This works both on Windows, Linux and MacOS

---
## Getting started
### Requirements
  * [Git](https://git-scm.com/downloads) for cloning the repo. Choose the correct installation for your OS.
  * Windows
    * [Visual Studio](https://visualstudio.microsoft.com/thank-you-downloading-visual-studio/?sku=Community&channel=Release&version=VS2022&source=VSLandingPage&cid=2030&passive=false): Install Visual Studio with `Desktop development with C++` selected
    * [GCC for windows](https://github.com/mstorsjo/llvm-mingw/releases) *(if don't have one already)*
      * Download and unzip the correct file for your platform (probably `msvcrt-x86_64`)
      * Add the `bin` directory in the unzipped folder to the `PATH` environment variable. [Here](https://stackoverflow.com/questions/44272416/how-to-add-a-folder-to-path-environment-variable-in-windows-10-with-screensho) is a tutorial on how to add items to `PATH`
    * [Python 3.10.5](https://www.python.org/ftp/python/3.10.5/python-3.10.5-amd64.exe): Any Python version above `3.8` works but make sure you check the box `add to path` on the last screen of the installation
  * Linux *(update the installation for your distro if different)*:
      * `Build essentials` (should be installed by default) and `python3` dependencies
        ```bash
        apt update; apt install build-essential python3 python3-venv -y
        ```

### Usage
Every time you see a code block, you should run it in a:  
  * `Terminal`: if you are on *Linux / MacOS*   
  * `Developer: PowerShell for VS`: if you're on *Windows* (this is installed with Visual Studio, search for it)

  1. ### Clone the repo and go into it:
        ```
        git clone https://github.com/darkarp/c-dictionary
        cd c-dictionary
        ```
  2. Create python virtual environment and activate it
        * Windows: 
            ```powershell 
            py -m venv venv
            .\venv\Scripts\activate
            ```
        * Linux / MacOS: 
            ```bash
            python3 -m venv venv
            source venv/bin/activate
            ```

  3. Generate Makefile
        ```powershell
        python makefile_gen.py
        ```
  4. Running the makefile
        * Windows  
            * Run this: `nmake all`  
            * For a quick help screen:
                `nmake help`
        * Linux / MacOS
            * Run this: `make all`  
            * For a comprehensive help screen:
                `make help`
  5. Running the example `main.exe`
        * Windows: `.\bin\main.exe`
        * Linux / MacOS: `./bin/main`
---
## Statistics Module (*optional*)
This project comes with a python statistics script, located in: `statistics/collisions.py`. This is an educational script which computes the ratio of collisions for this dictionary for a particular predefined size of the dict. 

It makes use of a C library for python. If you wish to run the `statistics/collisions.py`, the procedure is as follows:  

  ### 1. Install the C module:
```bash
python statistics/setup.py install
```
  ### 2. Run `statistics/collisions.py`
```bash
python statistics/collisions.py
```  
---
## TODO
  * Better documentation
  * Utility functions
  * Better stability check
  * Multiple hash support
  * File & membuffer I/O for saving/loading
  * Testing
  ---
## Learn More

For access to a community full of aspiring computer security experts, ranging from the complete beginner to the seasoned veteran,
join our:
  * Discord Server: [WhiteHat Hacking discord](https://discord.gg/beczNYP)
  * Website: [Whitehat Hacking Website](https://www.whitehathacking.tech)

If you wish to contact me, you can do so via: `mario@whitehathacking.tech`  

---
## License
<a href="https://github.com/darkarp/c-dictionary/blob/master/LICENSE"> AGPL-3.0 </a>