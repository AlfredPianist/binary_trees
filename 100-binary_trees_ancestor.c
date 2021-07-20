#include "binary_trees.h"

size_t binary_tree_depth(const binary_tree_t *tree);

/**
 * binary_trees_ancestor - Retrieves the common ancestor of two nodes.
 *
 * @first: The first node.
 * @second: The second node.
 *
 * Return: pointer to the common node, NULL if not found.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	size_t depth_first, depth_second;

	if (!first || !second)
		return (NULL);

	depth_first = binary_tree_depth(first);
	depth_second = binary_tree_depth(second);

	while (depth_first != depth_second)
	{
		if (depth_first > depth_second)
		{
			first = first->parent;
			depth_first--;
		}
		else
		{
			second = second->parent;
			depth_second--;
		}
	}

	while (first != second)
	{
		first = first->parent;
		second = second->parent;
	}

	return ((binary_tree_t *) first);
}

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
