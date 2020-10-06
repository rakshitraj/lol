class BinarySearchTreeNode:

    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

    def add_child(self, data):
        # BST will not have duplicates
        if data == self.data:
            return
        # if data is less than root node, add to left sub tree
        if data < self.data:
            if self.left:
                delf.left.add_child(data)
            else:
                self.left = BinarySearchTreeNode(data)
        # if data is greater than rrot node, add to the right
        if data > self.data:
            if self.right:
                self.right.add_child(data)
            else:
                self.right = BinarySearchTreeNode(data)

    def inorder(self: BinarySearchTreeNode ) -> List() :
        elements = []
        # left
        if self.left():
            elements += self.left.inorder()
        # root
        elements.append(self.data)
        # right
        if self.right:
            elements += self.right.inorder()
        
        return elements

        