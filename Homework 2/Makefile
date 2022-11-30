# @describe: Compiles the code
CC = g++

CFLAGS= -c -Wall

target: first
	
first: main.o BST.o TreeNode.o analysis.o
	$(CC) main.o BST.o TreeNode.o  analysis.o -o hw2
main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp
BST.o: BST.cpp
	$(CC) $(CFLAGS) BST.cpp
TreeNode.o: TreeNode.cpp
	$(CC) $(CFLAGS) TreeNode.cpp
analysis.o: analysis.cpp
	$(CC) $(CFLAGS) analysis.cpp


clean:
	rm *o hw2