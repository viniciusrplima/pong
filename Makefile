EXEC_FILE = launcher

CXX = g++

SRC_DIR = ./engine
BUILD_DIR = ./build
SRCS := $(shell find $(SRC_DIR) -name *.cpp)
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)

CPPINCS = -I"deps/" -I"deps/lua/include" -I"deps/box2d/include"
CPPLIBS = -L"deps/lua/lib" -L"deps/box2d/lib" -llua -ldl -lpthread -lsfml-system -lsfml-window \
			-lsfml-graphics -lsfml-audio -lX11 -lbox2d

default:
	-mkdir $(BUILD_DIR)
	make $(EXEC_FILE)

$(EXEC_FILE): $(OBJS)
	$(CXX) $(OBJS) -o $@ $(CPPLIBS)

$(BUILD_DIR)/%.cpp.o: %.cpp
	-mkdir -p $(dir $@)
	$(CXX) -c $< -o $@ $(CPPINCS) 

.PHONY: clean

clean:
	-rm $(EXEC_FILE) $(OBJS)

.PHONY: run

run:
	./$(EXEC_FILE)

.PHONY: lc

lc:
	git ls-files | grep src | xargs wc -l
