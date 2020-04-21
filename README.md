# The HamburgChimps Binary Search Tree

A reference implementation of a binary search tree in c.

For demonstration purposes, this repo contains a test harness and a Makefile to compile and link the BST implementation and test harness. You can then execute the test harness with `/.hc_bst_test`. This assumes an OS with `make` and `gcc`. 

## API

### `hc_bst_init() -> hc_bst*`

Initialize a BST for usage.

### `hc_bst_destroy(hc_bst**) -> void`

Destroy a BST.

### `hc_bst_insert(hc_bst* t, const char* k, const char* v) -> void`

Insert into a BST `t` a node with key `k` and value `v`.

### `hc_bst_get(hc_bst* t, const char* k) -> const char* v`

Returns the value `v` for the node with key `k` in the tree `t`. If the tree `t` does not
contain the key `k` then this function returns `NULL`. This function also returns `NULL` if
the given key `k` is `NULL`.

### `hc_bst_print(hc_bst* t) -> void`

Print the contents of a BST `t`.

## Addendum
Deletion, traversal, and other things are still to be implemented.
