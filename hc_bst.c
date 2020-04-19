#include "hc_bst.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hc_bst_node.h"

hc_bst* init_hc_bst() {
    hc_bst* tree = malloc(sizeof(hc_bst));
    tree->root = NULL;
    return tree;
}

static void insert_into_hc_bst_worker(hc_bst_node** nref, const char* k,
                                      const char* v) {
    if (*nref == NULL) {
        *nref = init_hc_bst_node(k, v);
        return;
    }

    if (strcmp(k, (*nref)->key) < 0) {
        insert_into_hc_bst_worker(&(*nref)->left, k, v);
        return;
    }

    if (strcmp(k, (*nref)->key) > 0) {
        insert_into_hc_bst_worker(&(*nref)->right, k, v);
    }
}

void insert_into_hc_bst(hc_bst* t, const char* k, const char* v) {
    insert_into_hc_bst_worker(&t->root, k, v);
}

static void print_hc_bst_worker(hc_bst_node* n, const char* node_addr) {
    if (n == NULL) {
        return;
    }

    printf("Node: %s\n", node_addr);
    printf("Key: %s\n", n->key);
    printf("Value %s\n", n->value);
    printf("\n\n");
    fflush(stdout);

    char* left_node_addr = malloc(120 * sizeof(char));
    strcpy(left_node_addr, node_addr);
    strcat(left_node_addr, "->left");
    print_hc_bst_worker(n->left, left_node_addr);
    free(left_node_addr);
    left_node_addr = NULL;

    char* right_node_addr = malloc(120 * sizeof(char));
    strcpy(right_node_addr, node_addr);
    strcat(right_node_addr, "->right");
    print_hc_bst_worker(n->right, right_node_addr);
    free(right_node_addr);
    right_node_addr = NULL;
}

void print_hc_bst(hc_bst* t) { print_hc_bst_worker(t->root, "root"); }

void destroy_hc_bst(hc_bst** t) {
    destroy_hc_bst_node(&(*t)->root);
    free(*t);
    *t = NULL;
}
