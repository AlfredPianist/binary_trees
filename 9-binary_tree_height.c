#include "binary_trees.h"
/**
 * binary_tree_height - height of a binary tree
 * @tree: input tree
 * Return: height of tree
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