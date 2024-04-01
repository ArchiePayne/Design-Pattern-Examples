# Define the project
project(ObserverPattern)

# Add all source files in the directory to the project
file(GLOB SOURCES "*.cpp")

add_executable(ObserverPattern ObserverPattern.cpp)