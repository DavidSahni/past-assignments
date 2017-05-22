hand: deal_hand.cpp card.hpp card.o deck.o deck.hpp hand.hpp hand.o player.hpp player.o game.hpp game.o
	g++ deal_hand.cpp card.o deck.o hand.o player.o game.o  -o gofish

card.o: card.cpp
	g++ card.cpp -c
deck.o: deck.cpp
	g++ deck.cpp -c
hand.o: hand.cpp
	g++ hand.cpp -c
player.o: player.cpp
	g++ player.cpp -c

game.o: game.cpp
	g++ game.cpp -c

clean:
	rm -f gofish *.o
