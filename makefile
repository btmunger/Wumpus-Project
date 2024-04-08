COMPILER = g++
EXE = run
CFLAGS = -Wall -g

$(EXE): bats.o event.o game.o gold.o main.o room.o stalactites.o wumpus.o passage.o closed.o armor.o
	$(COMPILER) bats.o event.o game.o gold.o main.o room.o stalactites.o wumpus.o passage.o closed.o armor.o -o run

bats.o: bats.cpp
	$(COMPILER) $(CFLAGS) -c bats.cpp

event.o: event.cpp
	$(COMPILER) $(CFLAGS) -c event.cpp

game.o: game.cpp
	$(COMPILER) $(CFLAGS) -c game.cpp

gold.o: gold.cpp
	$(COMPILER) $(CFLAGS) -c gold.cpp

room.o: room.cpp
	$(COMPILER) $(CFLAGS) -c room.cpp

stalactites.o: stalactites.cpp
	$(COMPILER) $(CFLAGS) -c stalactites.cpp

wumpus.o: wumpus.cpp
	$(COMPILER) $(CFLAGS) -c wumpus.cpp

closed.o: closed.cpp
	$(COMPILER) $(CFLAGS) -c closed.cpp

passage.o: passage.cpp
	$(COMPILER) $(CFLAGS) -c passage.cpp

armor.o: armor.cpp
	$(COMPILER) $(CFLAGS) -c armor.cpp

main.o: main.cpp
	$(COMPILER) $(CFLAGS) -c main.cpp