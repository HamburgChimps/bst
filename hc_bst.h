#ifndef HC_BST_H
#define HC_BST_H

#include "hc_bst_node.h"

typedef struct hc_bst {
    hc_bst_node* root;
} hc_bst;

hc_bst* hc_bst_init();

void hc_bst_insert(hc_bst* t, const char* k, const char* v);

void hc_bst_print(hc_bst* t);

void hc_bst_destroy(hc_bst** t);

#endif
