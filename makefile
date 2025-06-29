
# Compiler
CXX = g++

# Directories
SRC_DIR = src
LIB_DIR = lib

# Files
TARGET = game
SRC = $(SRC_DIR)/main.cpp

# Libraries
LIBS = -lSDL2

# Build rule
$(TARGET): $(SRC)
	$(CXX) -L$(LIB_DIR) -o $(TARGET) $(SRC) $(LIBS)

# Run rule
run: $(TARGET)
	./$(TARGET)
