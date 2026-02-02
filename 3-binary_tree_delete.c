#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_delete - Deletes an entire binary tree
 * @tree: Pointer to the root node of the tree to delete
 *
 * If tree is NULL, does nothing
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (!tree)
		return;

	/* Delete left subtree */
	if (tree->left)
		binary_tree_delete(tree->left);

	/* Delete right subtree */
	if (tree->right)
		binary_tree_delete(tree->right);

	/* Free the current node */
	free(tree);
}
