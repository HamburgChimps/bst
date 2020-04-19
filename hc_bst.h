#ifndef HC_BST_H
#define HC_BST_H

#include "hc_bst_node.h"

typedef struct hc_bst {
    hc_bst_node* root;
} hc_bst;

hc_bst* init_hc_bst();

void insert_into_hc_bst(hc_bst* t, const char* k, const char* v);

void print_hc_bst(hc_bst* t);

void destroy_hc_bst(hc_bst** t);

#endif
