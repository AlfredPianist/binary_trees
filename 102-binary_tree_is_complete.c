#include "binary_trees.h"
int check(const binary_tree_t *tree, unsigned int index, size_t size);

int binary_tree_is_complete(const binary_tree_t *tree)
{
	unsigned int i = 0;
	size_t size;

	if (tree == NULL)
		return (0);

	size = binary_tree_size(tree);
	return (check(tree, i, size));
}

int check(const binary_tree_t *tree, unsigned int index, size_t size)
{
	int is_complete = 0;

	if (!tree)
		return (1);

	if (index >= size)
		return (0);

	is_complete = check(tree->left, 2 * index + 1, size) &&
		check(tree->right, 2 * index + 2, size);
	return (is_complete);
}

size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t countnode = 0;

	if (!tree)
		return (0);

	countnode = 1 + binary_tree_size(tree->right) + binary_tree_size(tree->left);
	return (countnode);
}
