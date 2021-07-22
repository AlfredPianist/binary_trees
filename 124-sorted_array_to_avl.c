#include "binary_trees.h"

avl_t *rec_sorted_array_to_avl(avl_t *node, int *array,
			       int min, int max);

/**
 * sorted_array_to_avl - Converts a sorted array to an AVL tree.
 *
 * @array: The array to be converted.
 * @size: The size of the array.
 *
 * Return: pointer to the new root node of AVL or NULL otherwise.
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array)
		return (NULL);

	return (rec_sorted_array_to_avl(NULL, array, 0, size - 1));
}

/**
 * rec_sorted_array_to_avl - Converts a sorted array to an AVL tree.
 *                           Divide and conquer approach.
 *
 * @node: The parent node.
 * @array: The array to be converted.
 * @min: The leftmost limit of the subarray.
 * @max: The rightmost limit of the subarray.
 *
 * Return: pointer to the new root node of AVL or NULL otherwise.
 */
avl_t *rec_sorted_array_to_avl(avl_t *node, int *array, int min, int max)
{
	avl_t *new;

	if (min > max)
		return (NULL);

	new = (avl_t *) binary_tree_node((bst_t *) node, array[(min + max) / 2]);
	new->left = rec_sorted_array_to_avl(new, array,
					    min, ((min + max) / 2) - 1);
	new->right = rec_sorted_array_to_avl(new, array,
					     ((min + max) / 2) + 1, max);
	return (new);
}
