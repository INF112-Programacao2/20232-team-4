# Compiler and compiler flags
CXX = g++
CXXFLAGS = -std=c++17 -Iinclude -I/usr/local/include/opencv4
LDFLAGS = -L/home/cicilka/opencv/build/lib -lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_videoio -lopencv_imgcodecs

# Directories
SRCDIR = src
BUILDDIR = build
INCLUDEDIR = include

# Source and object files
SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(patsubst $(SRCDIR)/%.cpp, $(BUILDDIR)/%.o, $(SOURCES))

# Target executable
TARGET = a.out

# Default target
all: $(TARGET)

# Linking the executable
$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET) $(LDFLAGS)

# Compiling source files
$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Creating build directory
$(shell mkdir -p $(BUILDDIR))

# Clean up
clean:
	rm -rf $(BUILDDIR)/*.o $(TARGET)

.PHONY: all clean

