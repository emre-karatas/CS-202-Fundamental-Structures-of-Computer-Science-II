# Efficiently compile your code with Makefile
CC=g++
CFLAGS=-c -Wall

target: first

first: main.o RBTree.o TreeNode.o two34Tree.o
	$(CC) main.o RBTree.o TreeNode.o two34Tree.o -o converter

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp
RBTree.o: RBTree.cpp
	$(CC) $(CFLAGS) RBTree.cpp
TreeNode.o: TreeNode.cpp
	$(CC) $(CFLAGS) TreeNode.cpp
two34Tree.o: two34Tree.cpp
	$(CC) $(CFLAGS) two34Tree.cpp


clean:
	rm *o converter