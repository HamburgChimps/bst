#include "hc_bst.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    hc_bst* tree = hc_bst_init();

    assert(tree->root == NULL);

    hc_bst_insert(tree, "m", NULL);
    hc_bst_insert(tree, "a", NULL);
    hc_bst_insert(tree, "y", NULL);
    hc_bst_insert(tree, "o", NULL);
    hc_bst_insert(tree, "z", NULL);
    hc_bst_insert(tree, "b", NULL);
    hc_bst_insert(tree, "c", NULL);
    hc_bst_insert(tree, "d", NULL);
    hc_bst_insert(tree, "e", NULL);
    hc_bst_insert(tree, "f", NULL);

    hc_bst_traverse(tree, 0);

    // hc_bst_print(tree);

    // hc_bst_delete_key(tree, "y");

    // printf("\n\n\n===============================\n\n\n");

    // hc_bst_print(tree);

    hc_bst_destroy(&tree);
}
