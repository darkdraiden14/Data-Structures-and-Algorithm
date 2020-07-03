# A clas that represents an individual node in a binary tree

class Node:
    def __init__(self,key):
        self.left = None
        self.right = None
        self.key = key

#Create Root
root = Node(1)

root.left = Node(2)
root.right = Node(3)

root.left.left = Node(4)

tree = '''4 becomes left child of 2 
           1 
       /       \ 
      2          3 
    /   \       /  \ 
   4    None  None  None 
  /  \ 
None None'''

print(" We have created a tree : \n",tree)