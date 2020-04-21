#include "hc_bst.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "hc_node.h"

int main() {
    hc_bst* tree = hc_bst_init();
    assert(tree->root == NULL);
    hc_bst_insert(tree, "actor", "hugh jackman");
    hc_bst_insert(tree, "musician", "david guetta");
    hc_bst_insert(tree, "abolitionist", "William Lloyd Garrison");
    hc_bst_insert(tree, "translator", "Constance Garnett");
    hc_bst_insert(tree, "taco truck", "Sweeto Burrito");
    hc_bst_print(tree);
    printf("%s\n", hc_bst_get(tree, "taco truck"));
    printf("%s\n", hc_bst_get(tree, "taco truck 2"));
    printf("%s\n", hc_bst_get(tree, "musician"));
    hc_bst_destroy(&tree);
}
