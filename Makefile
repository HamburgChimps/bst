INCLUDE=./include
DEPS=$(wildcard ./deps/*.c)

.PHONY=clean

all:
	gcc -I $(INCLUDE) -o hc_bst_test \
		$(DEPS) \
		hc_bst_test.c \
		hc_bst.c

clean:
	rm -rf hc_bst_test
