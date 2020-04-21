#include "hc_node.h"

#include <stdlib.h>

hc_node* hc_node_init(const char* k, const char* v) {
    hc_node* node = malloc(sizeof(hc_node));
    node->left = NULL;
    node->right = NULL;

    node->key = k;
    node->value = v;

    return node;
}

void hc_node_destroy(hc_node** n) {
    if (*n == NULL) return;

    if ((*n)->left != NULL) hc_node_destroy(&(*n)->left);
    if ((*n)->right != NULL) hc_node_destroy(&(*n)->right);

    free(*n);
    *n = NULL;
}