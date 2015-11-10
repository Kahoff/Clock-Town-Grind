OBJS = main.o loadCore.o character.o playerCharacter.o coreData.o intro.o execute.o gameStates.o region.o town.o forest.o ocean.o mountain.o desert.o map.o monster.o battle.o quit.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)
FILENAME = CTG

$(FILENAME) : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $(FILENAME)

main.o : main.cpp coreData.h coreData.cpp loadCore.h loadCore.cpp execute.h execute.cpp quit.h quit.cpp 
	$(CC) $(CFLAGS) main.cpp

loadCore.o : coreData.h coreData.cpp loadCore.h loadCore.cpp
	$(CC) $(CFLAGS) loadCore.cpp

character.o : character.h character.cpp
	$(CC) $(CFLAGS) character.cpp

playerCharacter.o : character.h character.cpp playerCharacter.h playerCharacter.cpp
	$(CC) $(CFLAGS) playerCharacter.cpp

coreData.o : playerCharacter.h playerCharacter.cpp coreData.h coreData.cpp
	$(CC) $(CFLAGS) coreData.cpp

intro.o : intro.h intro.cpp
	$(CC) $(CFLAGS) intro.cpp

execute.o : coreData.h coreData.cpp execute.h execute.cpp map.h map.cpp battle.h battle.cpp 
	$(CC) $(CFLAGS) execute.cpp

gameStates.o : coreData.h coreData.cpp gameStates.h gameStates.cpp 
	$(CC) $(CFLAGS) gameStates.cpp

region.o : coreData.h coreData.cpp region.h region.cpp 
	$(CC) $(CFLAGS) region.cpp

town.o : region.h region.cpp town.h town.cpp 
	$(CC) $(CFLAGS) town.cpp

forest.o : region.h region.cpp forest.h forest.cpp 
	$(CC) $(CFLAGS) forest.cpp

ocean.o : region.h region.cpp ocean.h ocean.cpp 
	$(CC) $(CFLAGS) ocean.cpp

mountain.o : region.h region.cpp mountain.h mountain.cpp 
	$(CC) $(CFLAGS) mountain.cpp

desert.o : region.h region.cpp desert.h desert.cpp 
	$(CC) $(CFLAGS) desert.cpp

map.o : coreData.h coreData.cpp gameStates.h gameStates.cpp town.h town.cpp forest.h forest.cpp ocean.h ocean.cpp mountain.h mountain.cpp desert.h desert.cpp map.h map.cpp 
	$(CC) $(CFLAGS) map.cpp

monster.o : character.h character.cpp monster.h monster.cpp
	$(CC) $(CFLAGS) monster.cpp

battle.o : coreData.h coreData.cpp gameStates.h gameStates.cpp monster.h monster.cpp battle.h battle.cpp 
	$(CC) $(CFLAGS) battle.cpp

quit.o : quit.h quit.cpp
	$(CC) $(CFLAGS) quit.cpp

clean:
	del *.o  *~ $(FILENAME).exe
