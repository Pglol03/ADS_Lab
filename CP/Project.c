#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILES 10000

typedef struct file_s {
    char *filename;
    time_t timestamp;
} file_t;

typedef struct node_s {
    file_t *file;
    struct node_s *next;
} node_t;

typedef struct hashmap_s {
    node_t **table;
    int size;
} hashmap_t;

typedef struct tree_node_s {
    file_t *file;
    struct tree_node_s *left;
    struct tree_node_s *right;
} tree_node_t;

typedef struct time_tree_s {
    tree_node_t *root;
} time_tree_t;

hashmap_t *create_hashmap(int size) {
    hashmap_t *map = (hashmap_t *) malloc(sizeof(hashmap_t));
    map->table = (node_t **) calloc(size, sizeof(node_t *));
    map->size = size;
    return map;
}

int hash_string(char *str, int size) {
    int hash = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        hash = (hash * 31 + str[i]) % size;
    }
    return hash;
}

void add_file(hashmap_t *map, char *filename) {
    int index = hash_string(filename, map->size);
    node_t *head = map->table[index];
    node_t *new_node = (node_t *) malloc(sizeof(node_t));
    new_node->file = (file_t *) malloc(sizeof(file_t));
    new_node->file->filename = strdup(filename);
    new_node->file->timestamp = time(NULL);
    new_node->next = head;
    map->table[index] = new_node;
}

tree_node_t *insert_in_tree(tree_node_t *root, file_t *file) {
    if (root == NULL) {
        tree_node_t *new_node = (tree_node_t *) malloc(sizeof(tree_node_t));
        new_node->file = file;
        new_node->left = NULL;
        new_node->right = NULL;
        return new_node;
    } else if (file->timestamp < root->file->timestamp) {
        root->left = insert_in_tree(root->left, file);
    } else {
        root->right = insert_in_tree(root->right, file);
    }
    return root;
}

void print_files_in_order(tree_node_t *root) {
    if (root != NULL) {
        print_files_in_order(root->left);
        printf("%s\n", root->file->filename);
        print_files_in_order(root->right);
    }
}

void print_files_by_date(hashmap_t *map) {
    time_tree_t *tree = (time_tree_t *) malloc(sizeof(time_tree_t));
    tree->root = NULL;
    for (int i = 0; i < map->size; i++) {
        node_t *head = map->table[i];
        while (head != NULL) {
            tree->root = insert_in_tree(tree->root, head->file);
            head = head->next;
        }
    }
    print_files_in_order(tree->root);
}

int main() {
    hashmap_t *map = create_hashmap(MAX_FILES);
    add_file(map, "file1.txt");
    add_file(map, "file2.jpg");
    add_file(map, "file3.doc");
    add_file(map, "file4.mp4");
    add_file(map, "file5.pdf");
    print_files_by_date(map);
    return 0;
}
