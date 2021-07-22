#include "binary_trees.h"

size_t binary_tree_height(const binary_tree_t *tree);
void exec_level(const binary_tree_t *tree, size_t level, void (*func)(int));

/**
 * binary_tree_levelorder - Traverses each node of a binary tree in level order
 *                          (nodes of the same height).
 *
 * @tree: The binary tree to be traversed.
 * @func: Pointer to function to call for each node.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t level, height;

	if (!tree || !func)
		return;

	height = binary_tree_height(tree);
    printf("El alto del arbol: %lu\n", height);
	for (level = 0; level <= height; level++)
		exec_level(tree, level, func);
}

/**
 * exec_level - Executes function func at level.
 *
 * @tree: The root of the tree to calculate its height.
 * @level: The current height level of the node.
 * @func: The pointer to function to call for each node.
 */
void exec_level(const binary_tree_t *tree, size_t level, void (*func)(int))
{
	if (tree)
	{
		if (level == 0)
			func(tree->n);
		else
		{
			exec_level(tree->left, level - 1, func);
			exec_level(tree->right, level - 1, func);
		}
	}
}

/**
 * binary_tree_height - Measures the height of a binary tree.
 *
 * @tree: The root of the tree to calculate its height.
 *
 * Return: the tree's height, 0 if tree is NULL.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_left, height_right;

	if (!tree || !(tree->left || tree->right))
		return (0);

	height_left = binary_tree_height(tree->left);
	height_right = binary_tree_height(tree->right);

	return (1 + (height_left >= height_right ? height_left : height_right));
}