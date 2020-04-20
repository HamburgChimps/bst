#include "hc_bst_node.h"

#include <stdlib.h>

hc_bst_node* hc_bst_node_init(const char* k, const char* v) {
    hc_bst_node* node = malloc(sizeof(hc_bst_node));
    node->left = NULL;
    node->right = NULL;

    node->key = k;
    node->value = v;

    return node;
}

void hc_bst_node_destroy(hc_bst_node** n) {
    if (*n == NULL) return;

    if ((*n)->left != NULL) hc_bst_node_destroy(&(*n)->left);
    if ((*n)->right != NULL) hc_bst_node_destroy(&(*n)->right);

    free(*n);
    *n = NULL;
}