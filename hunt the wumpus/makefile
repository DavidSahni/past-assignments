htw: huntthewumpus.cpp room.hpp room.o player.hpp wumpus.o wumpus.hpp  event.o event.hpp game.o game.hpp bats.o bats.hpp pit.hpp pit.o gold.o gold.hpp rope.hpp rope.o
	g++ huntthewumpus.cpp room.o wumpus.o event.o game.o bats.o pit.o gold.o rope.o  -o htw

room.o: room.cpp room.hpp
	g++ room.cpp -c

event.o: event.cpp event.hpp
	g++ event.cpp -c

wumpus.o: wumpus.cpp wumpus.hpp
	g++ wumpus.cpp -c

game.o: game.cpp game.hpp
	g++ game.cpp -c

bats.o: bats.cpp bats.hpp
	g++ bats.cpp -c
pit.o: pit.cpp pit.hpp
	g++ pit.cpp -c
gold.o: gold.cpp gold.hpp
	g++ gold.cpp -c
rope.o: rope.hpp rope.cpp
	g++ rope.cpp -c

clean:
	rm -f *.o
