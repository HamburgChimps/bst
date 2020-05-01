all:
	gcc -o hc_bst_test hc_bst_test.c hc_bst.c

clean:
	rm -rf hc_bst_test
