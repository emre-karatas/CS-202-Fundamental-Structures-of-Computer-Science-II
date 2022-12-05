# @describe: Compiles the code
CC = g++

CFLAGS= -c -Wall

target: first
	
first: main.o DictionarySearchTree.o TreeNode.o DictionaryBST.o DictionaryAVLTree.o Dictionary23Tree.o twothree.o
	$(CC) main.o DictionarySearchTree.o TreeNode.o DictionaryBST.o DictionaryAVLTree.o Dictionary23Tree.o twothree.o -o hw3
main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp
DictionarySearchTree.o: DictionarySearchTree.cpp
	$(CC) $(CFLAGS) DictionarySearchTree.cpp
TreeNode.o: TreeNode.cpp
	$(CC) $(CFLAGS) TreeNode.cpp
DictionaryBST.o: DictionaryBST.cpp
	$(CC) $(CFLAGS) DictionaryBST.cpp
DictionaryAVLTree.o: DictionaryAVLTree.cpp
	$(CC) $(CFLAGS) DictionaryAVLTree.cpp
Dictionary23Tree.o: Dictionary23Tree.cpp
	$(CC) $(CFLAGS) Dictionary23Tree.cpp
twothree.o: twothree.cpp
	$(CC) $(CFLAGS) twothree.cpp



clean:
	rm *o hw3