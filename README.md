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
  * [Visual Studio](https://visualstudio.microsoft.com/thank-you-downloading-visual-studio/?sku=Community&channel=Release&version=VS2022&source=VSLandingPage&cid=2030&passive=false): Install Visual Studio with `Desktop development with C++` selected

### Usage
**Every time you see a code block, you should run it in a `terminal` if you are on linux OR a `Developer: PowerShell for VS` if you're on Windows (This is installed with Visual Studio).**
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
            apt update;
            apt install -y python3-venv
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
        * Linux
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
python `statistics/setup.py install`
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