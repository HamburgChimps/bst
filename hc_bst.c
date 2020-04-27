#include "hc_bst.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

hc_bst* hc_bst_init() {
    hc_bst* tree = malloc(sizeof(hc_bst));
    tree->root = NULL;
    return tree;
}

static void hc_bst_insert_worker(hc_node** n, const char* k, const char* v) {
    if (*n == NULL) {
        *n = hc_node_init(k, v);
        return;
    }

    int cmp_res = strcmp(k, (*n)->key);
    if (cmp_res < 0) {
        return hc_bst_insert_worker(&(*n)->left, k, v);
    }

    if (cmp_res > 0) {
        return hc_bst_insert_worker(&(*n)->right, k, v);
    }
}

void hc_bst_insert(hc_bst* t, const char* k, const char* v) {
    hc_bst_insert_worker(&t->root, k, v);
}

static hc_node** hc_bst_get_worker(hc_node** n, const char* k) {
    if (*n == NULL) return NULL;

    int cmp_res = strcmp(k, (*n)->key);
    if (cmp_res == 0) return n;
    if (cmp_res < 0) return hc_bst_get_worker(&(*n)->left, k);
    if (cmp_res > 0) return hc_bst_get_worker(&(*n)->right, k);

    return NULL;
}

const char* hc_bst_get(hc_bst* t, const char* k) {
    if (k == NULL) return NULL;

    hc_node** n = hc_bst_get_worker(&t->root, k);

    if (n == NULL) return NULL;
    return (*n)->value;
}

static void hc_bst_traverse_pre_order(hc_node* n) {
    if (n == NULL) return;

    hc_node_print(n);
    hc_bst_traverse_pre_order(n->left);
    hc_bst_traverse_pre_order(n->right);
}

static void hc_bst_traverse_in_order(hc_node* n) {
    if (n == NULL) return;

    hc_bst_traverse_in_order(n->left);
    hc_node_print(n);
    hc_bst_traverse_in_order(n->right);
}

static void hc_bst_traverse_post_order(hc_node* n) {
    if (n == NULL) return;

    hc_bst_traverse_post_order(n->left);
    hc_bst_traverse_post_order(n->right);
    hc_node_print(n);
}

void hc_bst_traverse(hc_bst* t, int order_flag) {
    if (t->root == NULL) return;
    if (order_flag == -1) return hc_bst_traverse_pre_order(t->root);
    if (order_flag == 0) return hc_bst_traverse_in_order(t->root);
    if (order_flag == 1) return hc_bst_traverse_post_order(t->root);
}

static hc_node** get_in_order_successor_worker(hc_node** n) {
    if ((*n)->left == NULL) return n;

    return get_in_order_successor_worker(n);
}

static hc_node** get_in_order_successor(hc_node** n) {
    if (*n == NULL) return NULL;
    if ((*n)->right == NULL) return NULL;

    return get_in_order_successor_worker(&(*n)->right);
}

static int is_leaf(hc_node* n) { return n->left == NULL && n->right == NULL; }

void hc_bst_delete_key(hc_bst* t, const char* k) {
    hc_node** n = hc_bst_get_worker(&t->root, k);

    if (n == NULL) return;
    if ((*n)->left == NULL && (*n)->right == NULL) {
        return hc_node_destroy(n);
    }
    if ((*n)->left == NULL && (*n)->right != NULL) {
        free(*n);
        if (*n == t->root) {
            t->root = (*n)->right;
        }
        *n = (*n)->right;
        return;
    }

    if ((*n)->left != NULL && (*n)->right == NULL) {
        free(*n);
        if (*n == t->root) {
            t->root = (*n)->right;
        }
        *n = (*n)->left;
        return;
    }

    hc_node** s = get_in_order_successor(n);
    (*n)->key = (*s)->key;
    (*n)->value = (*s)->value;

    if (is_leaf(*s)) {
        hc_node_destroy(s);
        return;
    }

    if ((*s)->left != NULL) {
        free(*s);
        *s = (*s)->left;
        return;
    }

    if ((*s)->right != NULL) {
        free(*s);
        *s = (*s)->right;
        return;
    }
}

static void hc_bst_print_worker(hc_node* n, const char* node_addr) {
    if (n == NULL) return;

    printf("Node: %s\n", node_addr);
    hc_node_print(n);
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
    hc_node_destroy(&(*t)->root);
    free(*t);
    *t = NULL;
}
