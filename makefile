CC = g++
AR = ar
LIB = lib/libgenetic.a
SRC_DIR = src
OBJ_DIR = build
SRC = rand_gen.cpp
OBJ = $(SRC:%.cpp=%.o)

OPT = -std=c++1z $(INCLUDE)
INCLUDE = -I./include
LIB_DIR = -L./lib

TEST_DIR = _test
TEST_SRC = test.cpp
TEST_BIN = test.exe
TEST_OPT = $(OPT) $(LIB_DIR) -lgenetic

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(OBJ_DIR)
	$(CC) $(OPT) -c -o $@ $<

$(LIB): $(OBJ:%.o=$(OBJ_DIR)/%.o)
	ar rcs $(LIB) $(OBJ_DIR)/$(OBJ)

test: $(LIB)
	g++ -o $(TEST_DIR)/$(TEST_BIN) $(TEST_DIR)/$(TEST_SRC) $(TEST_OPT)
