#ifndef HC_NODE_H
#define HC_NODE_H

typedef struct hc_node {
    struct hc_node* left;
    struct hc_node* right;
    const char* key;
    const char* value;
} hc_node;

hc_node* hc_node_init(const char* k, const char* v);

void hc_node_print(hc_node* n);

void hc_node_destroy(hc_node** n);

#endif
