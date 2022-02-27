#ifndef STDLIB_H
#define STDLIB_H
#include "stdlib.h"
#endif

#ifndef STRING_H
#define STRING_H
#include "string.h"
#endif

typedef enum node_type {
    PROG,
    STMTS,
    STMT,
    PRIM_DECL_STMT,
    IN_STMT,
    IDENTIFIER_NODE,
    TYPE
} node_type;

struct tree_node {
    node_type type;
    struct tree_node *children_head;
    struct tree_node *next_sibling;
    char value[255];
};

typedef struct tree_node tree_node;

struct tree_node* create_node(node_type type, char *value) {
    // allocate new node
    struct tree_node *new_node =
        (struct tree_node*) malloc(sizeof(struct tree_node));
    new_node -> type = type;
    if(value != NULL) strcpy(new_node -> value, value);
    new_node -> children_head = NULL;
    new_node -> next_sibling = NULL;
    return new_node;
}

struct tree_node* add_ready_to_parent(tree_node *parent, tree_node *child) {
    if(parent == NULL) return NULL;
    // search parent for the last child in list
    if(parent -> children_head == NULL)
        parent -> children_head = child;
    // traverse for the last child
    else {
        struct tree_node *current = parent -> children_head;
        while(current -> next_sibling != NULL)
            current = current -> next_sibling;
        current -> next_sibling = child;
    }
    return child;
}

struct tree_node* add_node_to_parent(tree_node *parent, node_type type, char *value) {
    if(parent == NULL) return NULL;

    struct tree_node *new_node = create_node(type, value);
    // search parent for the last child in list
    if(parent -> children_head == NULL)
        parent -> children_head = new_node;
    // traverse for the last child
    else {
        struct tree_node *current = parent -> children_head;
        while(current -> next_sibling != NULL)
            current = current -> next_sibling;
        current -> next_sibling = new_node;
    }

    return new_node;
}