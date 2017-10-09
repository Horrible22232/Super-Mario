#pragma once
#include <game\components\observer\event\EventList.h>
#include <SDL_mixer.h>



class AVL_Tree
{
	struct Node;
public:
	AVL_Tree();
	~AVL_Tree();

public:
	Mix_Chunk* getSound(Event& event);
	void addSound(Event& event, Mix_Chunk* soundFile);

private:
	int Height();
	bool isLeaf();
	Node* m_Node;
private:
	int m_height;

private:
	struct Node {
		Node* leftChild;
		Node* rightChild;
		Mix_Chunk* soundFile;
		Event event;
		int size;
	};
};






