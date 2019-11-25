OUTPUT=lab07

CXX=g++
CXXFLAGS=-Wall -g

LIB=$(wildcard *.h)
SRC=$(wildcard *.cpp)
OBJ=$(SRC:.cpp=.o)
DEP=$(SRC:.cpp=.d)

all: $(OUTPUT)

$(OUTPUT): $(OBJ)
	$(CXX) $(OBJ) -o $@
	
%.o: %.cpp $(LIB)
	$(CXX) -c $(CXXFLAGS) $<

clean:
	rm -f $(OUTPUT) $(OBJ)
	
run:
	@./$(OUTPUT)
	
check:
	@valgrind ./$(OUTPUT)

.PHONY: all clean run check 	
