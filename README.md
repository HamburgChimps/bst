# The HamburgChimps Binary Search Tree

A reference implementation of a binary search tree in c.

## API

### `hc_bst_init() -> hc_bst*`

Initialize a BST for usage.

### `hc_bst_destroy(hc_bst**) -> void`

Destroy a BST.

### `hc_bst_insert(hc_bst* t, const char* k, const char* v) -> void`

Insert into a BST `t` a node with key `k` and value `v`.

### `hc_bst_print(hc_bst* t) -> void`

Print the contents of a BST `t`.


## Addendum
Deletion, traversal, and other things are still to be implemented.