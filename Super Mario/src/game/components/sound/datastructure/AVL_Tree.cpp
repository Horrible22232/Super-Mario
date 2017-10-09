#include "stdafx.h"
#include "AVL_Tree.h"


AVL_Tree::AVL_Tree()
{
}


AVL_Tree::~AVL_Tree()
{
}



Mix_Chunk* AVL_Tree::getSound(Event& event)
{
	Node* current = m_Node;
	if (current->soundFile == NULL) {
		return NULL;
	}
	while (event != current->event) {
		if (event < current->event) { //Check if content is element of left subtree
			if (current->leftChild == NULL) {
				return NULL;
			}
			current = current->leftChild;
		}
		else {										//Check if content is element of right subtree
			if (current->rightChild == NULL) { 
				return NULL;
			}
			current = current->rightChild;
		}	
	}
	return current->soundFile;
}

void AVL_Tree::addSound(Event& event, Mix_Chunk* soundFile)
{

}


int AVL_Tree::Height()
{
	return m_height;
}

bool AVL_Tree::isLeaf()
{
	return (m_Node->leftChild == NULL && m_Node->rightChild == NULL);
}
