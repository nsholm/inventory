
C_SRC = src/main.cpp
C_SRC += src/inventory.cpp
C_SRC += src/process.cpp

all: 
	g++ -o main $(C_SRC) -Iinclude