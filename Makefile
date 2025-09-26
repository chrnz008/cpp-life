CXX = g++

SRC = src/src.cpp

OUT = game.exe

LIBS = -lraylib -lopengl32 -lgdi32 -lwinmm

CXXFLAGS = -std=c++17 -O2

all: $(OUT)

$(OUT): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(OUT) $(LIBS)

clean:
	rm -f $(OUT)

.PHONY: all clean

