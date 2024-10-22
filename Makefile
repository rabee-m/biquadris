CXX = g++
CXXFLAGS = -std=c++14 -g -Wall -MMD -Werror=vla
OBJECTS = board.o block.o main.o level.o level0.o level1.o level2.o level3.o level4.o cell.o blockgame.o interpreter.o textdisplay.o graphicdisplay.o window.o
DEPENDS = ${OBJECTS:.o=.d}
EXEC = biquadris
${EXEC} : ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -lX11

clean :
	rm ${DEPENDS} ${OBJECTS} ${EXEC}

-include ${DEPENDS} # reads the .d files and reruns dependencies

