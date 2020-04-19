# The HamburgChimps Binary Search Tree

A reference implementation of a binary search tree in c.

## API

### `init_hc_bst() -> hc_bst*`

Initialize a BST for usage.

### `destroy_hc_bst(hc_bst**) -> void`

Destroy a BST.

### `insert_into_hc_bst(hc_bst* t, const char* k, const char* v) -> void`

Insert into a BST `t` a node with key `k` and value `v`.

### `print_hc_bst(hc_bst* t) -> void`

Print the contents of a BST `t`.


## Addendum
Deletion, traversal, and other things are still to be implemented.
