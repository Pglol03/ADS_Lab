// C program to convert a binary tree
// to its mirror
#include <stdio.h>
#include <stdlib.h>

/* A binary tree node has data, pointer
to left child and a pointer to right child */
struct Node {
	int data;
	struct Node* left;
	struct Node* right;
};
int maxDepth(struct Node* node)
{
	if (node == NULL)
		return 0;
	else {
		/* compute the depth of each subtree */
		int lDepth = maxDepth(node->left);
		int rDepth = maxDepth(node->right);

		/* use the larger one */
		if (lDepth > rDepth)
			return (lDepth + 1);
		else
			return (rDepth + 1);
	}
}

/* Helper function that allocates a new node with the
given data and NULL left and right pointers. */
struct Node* newNode(int data)

{
	struct Node* node
		= (struct Node*)malloc(sizeof(struct Node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return (node);
}

static int count = 0;
int countnodes(struct Node *root)
{
    if(root != NULL)
    {
        countnodes(root->left);
        count++;
        countnodes(root->right);
    }
    return count;
}

/* Change a tree so that the roles of the left and
	right pointers are swapped at every node.

So the tree...
	4
	/ \
	2 5
	/ \
    1 3

is changed to...
	4
	/ \
	5 2
	/ \
	3 1
*/

void mirror(struct Node* node)
{
	if (node == NULL)
		return;
	else {
		struct Node* temp;

		/* do the subtrees */
		mirror(node->left);
		mirror(node->right);

		/* swap the pointers in this node */
		temp = node->left;
		node->left = node->right;
		node->right = temp;
	}
}

/* Helper function to print Inorder traversal.*/
void inOrder(struct Node* node)
{
	if (node == NULL)
		return;

	inOrder(node->left);
	printf("%d ", node->data);
	inOrder(node->right);
}



/* Driver program to test mirror() */
int main()
{
	struct Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	/* Print inorder traversal of the input tree */
	printf("Inorder traversal of the constructed"
		" tree is \n");
	inOrder(root);

	/* Convert tree to its mirror */
	mirror(root);

	/* Print inorder traversal of the mirror tree */
	printf("\nInorder traversal of the mirror tree"
		" is \n");
	inOrder(root);
    printf("\n");

    printf("Number of nodes in The Tree = %d ",countnodes(root));
    printf("\n");

    printf("Height of tree is %d", maxDepth(root));

	return 0;
}
