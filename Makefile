ROOT_DIR = $(realpath .)

CXX=g++
CFLAGS=-Wall
CPPFLAGS=$(CFLAGS) -std=c++11

INC=-I$(ROOT_DIR)/include

SRC=$(ROOT_DIR)/lib
OBJ=$(ROOT_DIR)/obj
TARGET=$(ROOT_DIR)/target
SRC_FILES=$(wildcard $(SRC)/*.cpp)
OBJ_FILES=$(patsubst $(SRC)/%.cpp,$(OBJ)/%.o,$(SRC_FILES))

.SILENT:
	build
	run

$(OBJ)/%.o: $(SRC)/%.cpp
	$(CXX) $(CPPFLAGS) $(INC) -c -o $@ $<

init:
	mkdir -p $(OBJ) $(TARGET)

.PHONY:
	build

build: clean init $(OBJ_FILES)
	$(CXX) $(CPPFLAGS) $(INC) main.cpp -o target/main $(OBJ_FILES)

run: build
	./target/main

clean:
	rm -rf $(TARGET) $(OBJ)
