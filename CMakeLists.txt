CMAKE_MINIMUM_REQUIRED(VERSION 3.22)

if(UNIX)
    project(snoop CXX)
    set(CMAKE_CXX_STANDARD 20)
    add_executable(snoop snoop.cpp)
    install(
        PROGRAMS ${CMAKE_CURRENT_BINARY_DIR}/snoop
        DESTINATION /usr/local/bin
    )
    install(
        PROGRAMS ${CMAKE_SOURCE_DIR}/data.json
        DESTINATION /etc/snoop
    )
    add_custom_target(uninstall
        COMMAND rm -drf /etc/snoop
        COMMAND rm /usr/local/bin/snoop
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    )
endif()