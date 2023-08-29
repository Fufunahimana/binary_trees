#include "binary_trees.h"
/**
 * binary_tree_levelorder - Function goes through a binary tree using
 * level-order traversal
 * @tree: node
 * @func: function to call
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t *list[1024];
	binary_tree_t *tmp;
	int k = 0, l = 0;

	if (tree == NULL || func == NULL)
		return;
	for (k = 0; k < 1024; k++)
		list[k] = NULL;
	list[0] = (binary_tree_t *)tree;
	k = 0;
	while (list[k] != NULL)
	{
		tmp = list[k];
		func(tmp->n);
		if (tmp->left != NULL)
		{
			l++;
			list[l] = tmp->left;
		}
		if (tmp->right != NULL)
		{
			l++;
			list[l] = tmp->right;
		}
		k++;
	}
}
