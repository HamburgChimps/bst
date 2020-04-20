#include "hc_bst.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hc_bst_node.h"

hc_bst* hc_bst_init() {
    hc_bst* tree = malloc(sizeof(hc_bst));
    tree->root = NULL;
    return tree;
}

static void hc_bst_insert_worker(hc_bst_node** nref, const char* k,
                                 const char* v) {
    if (*nref == NULL) {
        *nref = hc_bst_node_init(k, v);
        return;
    }

    if (strcmp(k, (*nref)->key) < 0) {
        hc_bst_insert_worker(&(*nref)->left, k, v);
        return;
    }

    if (strcmp(k, (*nref)->key) > 0) {
        hc_bst_insert_worker(&(*nref)->right, k, v);
    }
}

void hc_bst_insert(hc_bst* t, const char* k, const char* v) {
    hc_bst_insert_worker(&t->root, k, v);
}

static void hc_bst_print_worker(hc_bst_node* n, const char* node_addr) {
    if (n == NULL) {
        return;
    }

    printf("Node: %s\n", node_addr);
    printf("Key: %s\n", n->key);
    printf("Value %s\n", n->value);
    printf("\n\n");
    fflush(stdout);

    char* left_node_addr = malloc((strlen(node_addr) + 6 + 1) * sizeof(char));
    strcpy(left_node_addr, node_addr);
    strcat(left_node_addr, "->left");
    hc_bst_print_worker(n->left, left_node_addr);
    free(left_node_addr);
    left_node_addr = NULL;

    char* right_node_addr = malloc((strlen(node_addr) + 7 + 1) * sizeof(char));
    strcpy(right_node_addr, node_addr);
    strcat(right_node_addr, "->right");
    hc_bst_print_worker(n->right, right_node_addr);
    free(right_node_addr);
    right_node_addr = NULL;
}

void hc_bst_print(hc_bst* t) { hc_bst_print_worker(t->root, "root"); }

void hc_bst_destroy(hc_bst** t) {
    hc_bst_node_destroy(&(*t)->root);
    free(*t);
    *t = NULL;
}
