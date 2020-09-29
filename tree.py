class TreeNode:
    def __init__(self, name, designation):
        self.name = name
        self.designation = designation
        self.children = []
        self.parent = None
    
    def get_level(self):
        level = 0
        node = self.parent
        while node:
            level += 1
            node = node.parent
        return level

    def print_tree(self, qualifier):
        if qualifier == 'both':
            value = self.name + ' ( ' + self.designation + ' )'
        elif qualifier == 'name':
            value = self.name
        elif qualifier == 'designation':
            value = self.designation

        level = self.get_level()
        prefix = ''
        for i in range(level):
            prefix += '  |'
        prefix += '--' if self.parent else ''

        print (prefix + value)
        if self.children:
            for child in self.children:
                child.print_tree(qualifier)

    def add_child(self, child):
        child.parent = self
        self.children.append(child)

def build_management_tree():
    # CTO Hierarchy
    infra_head = TreeNode("Vishwa","Infrastructure Head")
    infra_head.add_child(TreeNode("Dhaval","Cloud Manager"))
    infra_head.add_child(TreeNode("Abhijit", "App Manager"))

    cto = TreeNode("Chinmay", "CTO")
    cto.add_child(infra_head)
    cto.add_child(TreeNode("Aamir", "Application Head"))

    # HR hierarchy
    hr_head = TreeNode("Gels","HR Head")

    hr_head.add_child(TreeNode("Peter","Recruitment Manager"))
    hr_head.add_child(TreeNode("Waqas", "Policy Manager"))

    ceo = TreeNode("Nilupul", "CEO")
    ceo.add_child(cto)
    ceo.add_child(hr_head)

    return ceo

if __name__ == '__main__':
    root_node = build_management_tree()
    root_node.print_tree("name")
    root_node.print_tree("designation")
    root_node.print_tree("both")