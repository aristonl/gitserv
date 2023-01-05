# Find Link
# /usr/local/lib/liblink -- Library
# /usr/local/include/link / /usr/local/include/Link/* -- Headers
find_library(LINK_LIBRARY
    NAMES link
    PATHS /usr/local/lib
    NO_DEFAULT_PATH
    )

find_path(LINK_INCLUDE_DIR
    NAMES Link.hpp
    PATHS /usr/local/include
    NO_DEFAULT_PATH
    )

# If the library is found, create LINK_FOUND
if(LINK_LIBRARY AND LINK_INCLUDE_DIR)
    set(LINK_FOUND TRUE)
else(
    set(LINK_FOUND FALSE)
    )
endif()