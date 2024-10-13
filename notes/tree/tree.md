---
title: Tree
layout: home
parent: Notes
---

# Tree, 树

```c
TreeNode* createNode(int value) {
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
	if (node == NULL) { printf("Error\n");
		exit(EXIT_FAILURE);
	}
	node->value = value;
	node->left = NULL;
	node->right = NULL;
	return node;
}
```

```c
TreeNode* createBinaryTree() {
	// 创建根节点
	TreeNode* root = createNode(1);
	
	// 创建左子树
	root->left = createNode(2);
	root->left->left = createNode(4);
	root->left->right = createNode(5);
	
	// 创建右子树
	root->right = createNode(3);
	root->right->left = createNode(6);
	root->right->right = createNode(7);
	
	return root;
}
```

```c
```

## 二叉树常见术语

- 根节点（root node）：位于二叉树顶层的节点，没有父节点。
- 叶节点（leaf node）：没有子节点的节点，其两个指针均指向 `None` 。
- 边（edge）：连接两个节点的线段，即节点引用（指针）。
- 节点所在的层（level）：从顶至底递增，根节点所在层为 1 。
- 节点的度（degree）：节点的子节点的数量。在二叉树中，度的取值范围是 0、1、2 。
- 二叉树的高度（height）：从根节点到最远叶节点所经过的边的数量。
- 节点的深度（depth）：从根节点到该节点所经过的边的数量。
- 节点的高度（height）：从距离该节点最远的叶节点到该节点所经过的边的数量。

---

- 度
- 叶子
- 孩子
- 双亲
- 子孙
- 祖先
- 层
- 兄弟
- 堂兄弟
- ⼆叉树的度
- ⼆叉树的深度



- **满⼆叉树**：在⼀棵⼆叉树中，如果所有分支结点都存在左⼦树和右⼦树， 并且所有叶⼦结点都在同⼀层上，这样的⼆叉树称为满⼆叉树。
- https://www.hello-algo.com/chapter_tree/binary_tree/#1_1

## Readings

- <https://www.hello-algo.com/chapter_tree/binary_tree/>