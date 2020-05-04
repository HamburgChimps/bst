all:
	gcc -o hc_bst_test \
		include/hc-q/hc_q.c \
		hc_bst_test.c \
		hc_bst.c

clean:
	rm -rf hc_bst_test
