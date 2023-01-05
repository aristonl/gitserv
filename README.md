# gitserv - git front-end solution

`gitserv` is a git server hosting program which includes a web GUI built with 
[Link](https://github.com/N11Software/Link) and a modified version of 
[soft serve](https://github.com/charmbracelet/soft-serve), an ssh GUI for git.

## Software Requirements
Since this is a git-based program, you need git to be installed. 
For compiling, install cmake, gcc, ninja, and go. The web front
end uses Link, an http library in C++ built by N11. 
>   ------------------------------------------------------------------------------
> 
>   **NOTE**: *Link cannot be built on case-insensitive file systems, such as a
>   default macOS installation. You will need to use a case-sensitive file
>   system, not use the web front end, or modify the files in gitserv and Link.*
> 
>   ------------------------------------------------------------------------------

## Building gitserv
gitserv uses cmake to build. To build, run the following commands:

    $ mkdir build
    $ cd build
    $ cmake --GNinja ..
    $ ninja

>	------------------------------------------------------------------------------
>
>	**NOTE**: *It is possible to build this using Make rather than Ninja, but this
>	is untested for both Link and gitserv.*
>
>	------------------------------------------------------------------------------
## License
gitserv is licensed under BSD 3; see LICENSE.
git and libgit2 are licensed under GPLv2; see COPYING. git and libgit2
use certain sources that are either not BSD 3 Clause or GPLv2. See their
respective COPYING files for more info.
