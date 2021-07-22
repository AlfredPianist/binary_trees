#include "binary_trees.h"
size_t binary_tree_depth(const binary_tree_t *tree);

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
    size_t depth_first, depth_second;
    binary_tree_t *cp_first = (binary_tree_t *)first;
    binary_tree_t *cp_second = (binary_tree_t *)second;
	
	if (first == NULL || second == NULL)
		return (NULL);

	depth_first = binary_tree_depth(cp_first);
	depth_second = binary_tree_depth(cp_second);
    
	
    while (depth_second > depth_first)
    {
        cp_second = cp_second->parent;
        depth_second--;
    }
	while (depth_first > depth_second)
    {
		cp_first = cp_first->parent;
        depth_second--;
    }
    while (cp_first && cp_second)
	{
		if (cp_first == cp_second)
			return (cp_first);
            
		cp_first = cp_first->parent;
		cp_second = cp_second->parent;
	}
	return (NULL);
}

size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	if (!tree)
		return (0);

	while (tree->parent != NULL)
	{
		depth++;
		tree = tree->parent;
	}
	return (depth);
}
