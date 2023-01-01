# gitserv - git front-end solution

`gitserv` is a git server hosting program which includes a web GUI built with 
[Link](https://github.com/N11Software/Link) and a modified version of 
[soft serve](https://github.com/charmbracelet/soft-serve), an ssh GUI for git.

## Software Requirements
Since this is a git-based program, you need git to be installed. 
For compiling, install cmake, gcc, ninja, and go. The web front
end uses Link, an http library in C++ built by N11. As of 1/1/2023,
gitserv can only build on Linux.

## Building gitserv
gitserv uses cmake to build. To build, run the following commands:
```
    $ mkdir build
    $ cd build
    $ cmake --GNinja ..
    $ ninja
```

Copyright (c) 2023 aristonl. gitserv is licensed under BSD 3; see LICENSE.
git and libgit2 are licensed under GPLv2; see COPYING. git and libgit2
use certain sources that are either not BSD 3 Clause or GPLv2. See their
respective COPYING files for more info.