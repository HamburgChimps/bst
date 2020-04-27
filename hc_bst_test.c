#include "hc_bst.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    hc_bst* tree = hc_bst_init();

    assert(tree->root == NULL);

    hc_bst_insert(tree, "m", NULL);
    hc_bst_insert(tree, "a", NULL);
    hc_bst_insert(tree, "z", NULL);
    hc_bst_insert(tree, "o", NULL);
    hc_bst_insert(tree, "q", NULL);
    hc_bst_insert(tree, "p", NULL);

    hc_bst_print(tree);

    hc_bst_destroy(&tree);
}
