INCLUDE=./include
DEPS=$(wildcard ./deps/*.c)
OBJ=hc_bst_test
SRC=$(wildcard ./src/*.c)

.PHONY=clean

all:
	gcc -I $(INCLUDE) -o $(OBJ) \
		$(DEPS) \
		$(SRC)

clean:
	rm -rf $(OBJ)
