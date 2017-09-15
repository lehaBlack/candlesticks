LIBS = -lglut -lGL -lGLU -pthread
CPP = -std=c++11
H_FILES = ../Arrow.hpp ../Candle.hpp ../DrawingBoard.hpp ../JapaniseCandle.hpp ../Object.hpp ../Plotter.hpp ../Scalle.hpp ../Window.hpp
O_FILES = main.o Plotter.o Window.o
all: test

test: $(O_FILES)
	g++ $(CPP) $(O_FILES) -fpermissive -o test $(LIBS)

main.o: ../main.cpp $(H_FILES)
	g++ $(CPP) -c -fpermissive ../main.cpp

Plotter.o: ../Plotter.cpp $(H_FILES)
	g++ $(CPP) -c -fpermissive ../Plotter.cpp
	
Window.o: ../Window.cpp $(H_FILES)
	g++ $(CPP) -c -fpermissive ../Window.cpp
	
clean:
	rm -rf *.o test
