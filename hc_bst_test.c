#include "hc_bst.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    hc_bst* tree = hc_bst_init();

    assert(tree->root == NULL);

    hc_bst_insert(tree, "actor", "hugh jackman");
    hc_bst_insert(tree, "musician", "david guetta");
    hc_bst_insert(tree, "abolitionist", "William Lloyd Garrison");
    hc_bst_insert(tree, "aardvark", "Arthur");

    hc_bst_delete_key(tree, "abolitionist");

    hc_bst_print(tree);

    hc_bst_destroy(&tree);
}
