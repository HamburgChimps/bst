#include "hc_bst.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "hc_bst_node.h"

int main() {
    hc_bst* tree = init_hc_bst();
    assert(tree->root == NULL);
    insert_into_hc_bst(tree, "actor", "hugh jackman");
    insert_into_hc_bst(tree, "musician", "david guetta");
    insert_into_hc_bst(tree, "abolitionist", "William Lloyd Garrison");
    insert_into_hc_bst(tree, "translator", "Constance Garnett");
    insert_into_hc_bst(tree, "taco truck", "Sweeto Burrito");
    print_hc_bst(tree);
    destroy_hc_bst(&tree);
}
