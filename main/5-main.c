#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	binary_tree_t *root, *root2;
	int ret;

	root = binary_tree_node(NULL, 98);
	root->left = binary_tree_node(root, 12);
	root->right = binary_tree_node(root, 402);
	binary_tree_insert_right(root->left, 54);
	binary_tree_insert_right(root, 128);
	binary_tree_print(root);

	ret = binary_tree_is_root(root);
	printf("Is %d a root: %d\n", root->n, ret);
	ret = binary_tree_is_root(root->right);
	printf("Is %d a root: %d\n", root->right->n, ret);
	ret = binary_tree_is_root(root->right->right);
	printf("Is %d a root: %d\n", root->right->right->n, ret);

	root2 = binary_tree_node(NULL, 8);
	ret = binary_tree_is_root(root2);
	binary_tree_print(root2);
	printf("Is %d a root: %d\n", root2->n, ret);

	ret = binary_tree_is_root(NULL);
	printf("Is %p a root: %d\n", NULL, ret);

	return (0);
}
