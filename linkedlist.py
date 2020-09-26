#!/usr/bin/pyhton3

class Node :
    """A class used to implement nodes for a linked list.
    ...

    Attributes
    ----------
    data : auto
        Data stored in node
    next : pointer
        contains the address of next node
    """
    def __init__(self, data=None, next=None) :
        """
        Constructor to initialize object

        :param data: dtype<>
            data to store in node. Default is None, empty node)
        :param next: address
            address of the next node (default is None i.e node points to nothing)
        :rtype : void
        """
        self.data = data
        self.next = next

class LinkedList :
    """
    Class to implement Linked List
    ...

    Attributes
    ----------

    head : pointer
        Pionts to the start of the linked list
    """
    
    def __init__(self):
        self.head = None

    def print(self) :
        """
        Function to print the linked list
        :param self : reference to current obj, automatically passed
        :rtype : void
        """
        if self.head is None :
            print("Linked List does not exist.")
            return
        itr = self.head
        llstr = ''
        while itr :
            llstr += str(itr.data) + "--->"
            itr = itr.next
        print(llstr)

    def length(self):
        """Function to return length of Linked List

        :param self : refernce to current obj, automatically passed
        :returns : count ; number of nodes
        :rtype: int
        """ 
        if self.head is None:
            return 0
        count = 0
        itr = self.head
        while itr :
            itr = itr.next
            count += 1
        return count

    def push_front(self, data) :
        node = Node(data, self.head)
        self.head = node

    def push_back(self, data) :
        if self.head is None:
            self.head = Node(data, None)
            return
 
        itr = self.head
        while itr.next :
            itr = itr.next
        itr.next = Node(data, None)

    def assign_values(self, data_list):
        self.head = None
        for data in data_list:
            self.push_back(data)
    
    def push_values(self, data_list):
        for data in data_list:
            self.push_back(data)

    def insert_at(self, index, data):
        if index<0 or index>self.length() :
            raise Exception("Invalid index")

        if index == 0:
            self.push_front(data)
            return
        count = 0
        itr = self.head
        while itr:
            if count+1 == index :
                itr.next = Node(data, itr.next)
                break
            itr = itr.next
            count += 1
    
    def remove_at(self, index):
        if index<0 or index>self.length() :
            raise Exception("Invalid index")

        if index == 0:
            self.head = self.head.next
            return

        count = 0 
        itr = self.head

        while itr:
            if count+1 == index :
                itr.next = itr.next.next
                break
            itr = itr.next
            count += 1

if __name__ == '__main__' :
    ll = LinkedList()
    data_list = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j']
    ll.push_values(data_list)
    ll.print()
    ll.remove_at(4)
    ll.print()
    ll.insert_at(4, '4')
    ll.print()
