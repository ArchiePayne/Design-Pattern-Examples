# Define the project
project(FactoryPattern)

# Add all source files in the directory to the project
file(GLOB SOURCES "*.cpp")

add_executable(FactoryPattern FactoryPattern.cpp)