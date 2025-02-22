cmake_minimum_required(VERSION 3.10)
project(SocketProject)

# Add socketUtil library
add_library(socketUtil STATIC
    socketUtil/socketutil.c
)

target_include_directories(socketUtil PUBLIC
    socketUtil
)

# Add socketClient executable
add_executable(socketClient
    socketClient/main.c
)

target_link_libraries(socketClient PRIVATE
    socketUtil
)

target_include_directories(socketClient PRIVATE
    socketUtil
)


# Add socketServer executable
add_executable(socketServer
    socketServer/main.c
)

target_link_libraries(socketServer PRIVATE
    socketUtil
)

target_include_directories(socketServer PRIVATE
    socketUtil
)