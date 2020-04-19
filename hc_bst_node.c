#include "hc_bst_node.h"

#include <stdlib.h>

hc_bst_node* init_hc_bst_node(const char* k, const char* v) {
    hc_bst_node* node = malloc(sizeof(hc_bst_node));
    node->left = NULL;
    node->right = NULL;

    node->key = k;
    node->value = v;

    return node;
}

void destroy_hc_bst_node(hc_bst_node** n) {
    if (*n == NULL) return;

    if ((*n)->left != NULL) destroy_hc_bst_node(&(*n)->left);
    if ((*n)->right != NULL) destroy_hc_bst_node(&(*n)->right);

    free(*n);
    *n = NULL;
}