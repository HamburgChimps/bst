#ifndef HC_BST_NODE_H
#define HC_BST_NODE_H

typedef struct hc_bst_node {
    struct hc_bst_node* left;
    struct hc_bst_node* right;
    const char* key;
    const char* value;
} hc_bst_node;

hc_bst_node* init_hc_bst_node(const char* k, const char* v);

void destroy_hc_bst_node(hc_bst_node** n);

#endif
