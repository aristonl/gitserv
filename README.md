# gitserv - git front-end solution

`gitserv` is a git server hosting program which includes a web GUI built with 
[Link](https://github.com/N11Software/Link) and a modified version of 
[soft serve](https://github.com/charmbracelet/soft-serve), an ssh GUI for git.

## Software Requirements
Since this is a git-based program, you need git to be installed. 
For compiling, install cmake, gcc, ninja, and go. The web front
end uses Link, an http library in C++ built by N11.

## Building gitserv
Run "cmake -GNinja ." in the project root. You may also use make
as your build system but it isn't recommended and not tested. Then 
run "ninja"; it will build an executable named "gitserv" to which 
you can run with "./gitserv".

Copyright (c) 2022 aristonl. gitserv is licensed under BSD 3; see LICENSE.
git and libgit2 are licensed under GPLv2; see COPYING. git and libgit2
use certain sources that are either not BSD 3 Clause or GPLv2. See their
respective COPYING files for more info.