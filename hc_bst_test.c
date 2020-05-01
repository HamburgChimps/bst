#include "hc_bst.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define TEST_KEYS_SIZE 10

int main() {
    hc_bst* tree = hc_bst_init();

    assert(tree->root == NULL);

    const char* test_keys[TEST_KEYS_SIZE] = {"m", "a", "y", "o", "z",
                                             "b", "c", "d", "e", "f"};

    for (int i = 0; i < TEST_KEYS_SIZE; ++i)
        hc_bst_insert(tree, test_keys[i], NULL);

    hc_bst_traverse(tree, -1);
    hc_bst_traverse(tree, 0);
    hc_bst_traverse(tree, 1);
    hc_bst_traverse(tree, 2);

    hc_bst_delete_key(tree, "y");

    hc_bst_print(tree);

    hc_bst_destroy(&tree);
}
