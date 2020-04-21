#ifndef HC_BST_H
#define HC_BST_H

#include "hc_node.h"

typedef struct hc_bst {
    hc_node* root;
} hc_bst;

hc_bst* hc_bst_init();

void hc_bst_insert(hc_bst* t, const char* k, const char* v);

const char* hc_bst_get(hc_bst* t, const char* k);

void hc_bst_print(hc_bst* t);

void hc_bst_destroy(hc_bst** t);

#endif
