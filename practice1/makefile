CXX = g++
CXXFLAGS = -std=c++11 -Wall
SRC_DIR = .
OBJ_DIR = obj
BIN_DIR = exec
EXECUTABLE = $(BIN_DIR)/program

SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SOURCES))

all: $(EXECUTABLE)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/bit_operations.o: bitlib/bit_operations.cpp bitlib/bit_operations.h
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/bitout.o: bitoutlib/bitout.cpp bitoutlib/bitout.h
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(EXECUTABLE): $(OBJECTS) $(OBJ_DIR)/bit_operations.o $(OBJ_DIR)/bitout.o
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

.PHONY:
