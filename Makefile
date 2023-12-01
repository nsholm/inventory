
C_SRC = src/main.cpp
C_SRC += src/inventory.cpp

all: 
	g++ -o main $(C_SRC) -Iinclude