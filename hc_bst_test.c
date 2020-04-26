#include "hc_bst.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    hc_bst* tree = hc_bst_init();

    assert(tree->root == NULL);

    hc_bst_insert(tree, "b", NULL);
    hc_bst_insert(tree, "a", NULL);
    hc_bst_insert(tree, "c", NULL);

    hc_bst_delete_key(tree, "b");

    hc_bst_destroy(&tree);
}
