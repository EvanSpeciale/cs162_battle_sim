main: main.o Character.o Vampire.o Barbarian.o BlueMen.o Medusa.o HarryPotter.o Menu.o
	g++ -std=c++11 main.o Character.o Vampire.o Barbarian.o BlueMen.o Medusa.o HarryPotter.o Menu.o -o main

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

Character.o: Character.cpp Character.hpp
	g++ -std=c++11 -c Character.cpp

Vampire.o: Vampire.cpp Vampire.hpp
	g++ -std=c++11 -c Vampire.cpp

Barbarian.o: Barbarian.cpp Barbarian.hpp
	g++ -std=c++11 -c Barbarian.cpp

BlueMen.o: BlueMen.cpp BlueMen.hpp
	g++ -std=c++11 -c BlueMen.cpp

Medusa.o: Medusa.cpp Medusa.hpp
	g++ -std=c++11 -c Medusa.cpp

HarryPotter.o: HarryPotter.cpp HarryPotter.hpp
	g++ -std=c++11 -c HarryPotter.cpp

Menu.o: Menu.cpp Menu.hpp
	g++ -std=c++11 -c Menu.cpp

clean:
	rm *.o main
