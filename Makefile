CC=g++
SRC=$(wildcard src/*.cpp) 
SRCC=$(wildcard src/*.c)
OBJ=$(SRC:.cpp=.o) $(SRCC:.c=.o)
CFLAGS= -g
LFLAGS=-lsfml-graphics -lsfml-window -lsfml-system
DPS=$(OBJ:.o=.d)



bin/cerraria: $(OBJ)
	@echo $(OBJ)
	$(CC) -o bin/cerraria $^ $(LFLAGS) 



clean:
	rm -f bin/factorgl src/*.o

%.o: %.cpp
	$(CC) -MMD -MP -c $< -o $@ -Iinclude $(CFLAGS)

%.o: %.c
	$(CC) -MMD -MP -c $< -o $@ -Iinclude $(CFLAGS)



-include $(DPS)