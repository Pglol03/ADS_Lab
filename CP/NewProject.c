#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Struct definitions

typedef struct time_based_tree_node
{
    char *key;
    char *value;
    time_t timestamp;
    struct time_based_tree_node *left;
    struct time_based_tree_node *right;
    struct time_based_tree_node *parent;
} time_based_tree_node;

typedef struct time_based_tree
{
    time_based_tree_node *root;
    time_based_tree_node *head;
} time_based_tree;

typedef struct linked_list_node {
    time_based_tree_node *data;
    struct linked_list_node *next;
    struct linked_list_node *prev;
} linked_list_node;


// Function prototypes

time_based_tree_node *time_based_tree_node_create(char *key, char *value, time_t timestamp);
void time_based_tree_insert(time_based_tree *tree, char *key, char *value, time_t timestamp);
void time_based_tree_traverse_in_order(time_based_tree_node *node);
void time_based_tree_print(time_based_tree *tree);
void linked_list_node_insert(time_based_tree *tree, time_based_tree_node *node);
void linked_list_traverse_forward(time_based_tree *tree);

// Main function

int main()
{
    time_based_tree tree;
    tree.root = NULL;
    tree.head = NULL;

    // Insert nodes into the tree
    time_based_tree_insert(&tree, "key1", "value1", time(NULL));
    time_based_tree_insert(&tree, "key2", "value2", time(NULL) + 1);
    time_based_tree_insert(&tree, "key3", "value3", time(NULL) - 1);

    // Print the tree in order
    printf("Time-based tree:\n");
    time_based_tree_print(&tree);

    // Print the linked list in forward order
    printf("Linked list (forward):\n");
    linked_list_traverse_forward(&tree);

    return 0;
}

// Function implementations

time_based_tree_node *time_based_tree_node_create(char *key, char *value, time_t timestamp)
{
    time_based_tree_node *node = (time_based_tree_node *)malloc(sizeof(time_based_tree_node));
    node->key = key;
    node->value = value;
    node->timestamp = timestamp;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
    return node;
}

void time_based_tree_insert(time_based_tree *tree, char *key, char *value, time_t timestamp)
{
    // Create a new time-based tree node
    time_based_tree_node *node = time_based_tree_node_create(key, value, timestamp);

    // Insert the node into the time-based tree
    if (tree->root == NULL)
    {
        tree->root = node;
        tree->head = node;
    }
    else
    {
        time_based_tree_node *curr = tree->root;
        while (1)
        {
            if (timestamp > curr->timestamp)
            {
                if (curr->right == NULL)
                {
                    curr->right = node;
                    node->parent = curr;
                    linked_list_node_insert(tree, node);
                    break;
                }
                else
                {
                    curr = curr->right;
                }
            }
            else
            {
                if (curr->left == NULL)
                {
                    curr->left = node;
                    node->parent = curr;
                    linked_list_node_insert(tree, node);
                    break;
                }
                else
                {
                    curr = curr->left;
                }
            }
        }
    }
}

void time_based_tree_traverse_in_order(time_based_tree_node *node)
{
    if (node != NULL)
    {
        time_based_tree_traverse_in_order(node->left);
        printf("Key: %s, Value: %s, Timestamp: %ld\n", node->key, node->value, node->timestamp);
        time_based_tree_traverse_in_order(node->right);
    }
}

void time_based_tree_print(time_based_tree *tree)
{
    time_based_tree_traverse_in_order(tree->root);
    printf("\n");
}

void linked_list_node_insert(time_based_tree *tree, time_based_tree_node *node) {
    // Create a new linked list node
    linked_list_node *list_node = (linked_list_node *) malloc(sizeof(linked_list_node));
    list_node->data = node;

    // Insert the node into the linked list
    if (tree->head == NULL) {
        tree->head = list_node;
    } else {
        linked_list_node *curr = tree->head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = list_node;
        list_node->prev = curr;
    }
}


void linked_list_traverse_forward(time_based_tree *tree)
{
    linked_list_node *curr = tree->head;
    while (curr != NULL)
    {
        time_based_tree_node *node = (time_based_tree_node *)curr->data;
        printf("Key: %s, Value: %s, Timestamp: %ld\n", node->key, node->value, node->timestamp);
        curr = curr->next;
    }
}