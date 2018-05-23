CXX = g++-5
CXXFLAGS = -std=c++14 -Wall -MMD
EXEC = cc3k
OBJECTS = main.o boostAtk.o halfling.o enemy.o boostDef.o woundAtk.o woundDef.o restoreHealth.o poisionHealth.o character.o shade.o troll.o vampire.o goblin.o drow.o player.o item.o samllTresure.o normalTresure.o merchantHoard.o dragonHoard.o elf.o human.o dwarf.o orcs.o merchant.o dragon.o cell.o floor.o spawn.o subject.o 
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
.PHONY: clean
