#include "binary_trees.h"

/**
 * binary_tree_depth - Measures the depth of a binary tree.
 *
 * @tree: A node of the tree to calculate its depth.
 *
 * Return: the tree's depth, 0 if tree is NULL.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth;

	if (!tree || !(tree->parent))
		return (0);

	depth = binary_tree_depth(tree->parent);

	return (1 + depth);
}
