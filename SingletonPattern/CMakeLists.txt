# Define the project
project(SingletonPattern)

# Add all source files in the directory to the project
file(GLOB SOURCES "*.cpp")

add_executable(SingletonPattern SingletonPattern.cpp)