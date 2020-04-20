#ifndef HC_BST_NODE_H
#define HC_BST_NODE_H

typedef struct hc_bst_node {
    struct hc_bst_node* left;
    struct hc_bst_node* right;
    const char* key;
    const char* value;
} hc_bst_node;

hc_bst_node* hc_bst_node_init(const char* k, const char* v);

void hc_bst_node_destroy(hc_bst_node** n);

#endif
