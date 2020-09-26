class Node :
    """
    Attributes
    ----------
    data : char/int
            data stored in node
    prev : pointer
            pionter to previous node
    next : pionter
            pionter to next node   
    """
    def __init__(self, data=None, prev=None, next=None):
        self.data = data
        self.prev = prev
        self.next = next

class doubleLinkedList :
    """
    Attributes
    ----------
    head : pointer
            points to the first node of the linked list
    tail : pointer
            points to the last node og the list
    """
    def __init__(self) :
        self.head = None
        self.tail = None

    def print(self) :
        if self.head is None:
            print("Linked List does not exist...")
            return
        itr = self.head
        llstr = '| <==>'
        while itr :
            llstr += str(itr.data) + '<==>'
            itr = itr.next
            if itr == self.head :
                break
        llstr += ' |'
        print(llstr)

    def length(self) :
        if self.head is None:
            return 0
        count = 0
        itr = self.head
        while itr:
            count += 1
            itr = itr.next
            # if itr == self.head:
            #     break
        return count

    def push_front(self, data)  : 
        node = Node(data, None, self.head)
        if self.head != None : 
            self.head.prev = node
        self.head = node
        if self.tail is None:
            self.tail = node

    def push_back(self, data) :
        if self.head is None:
            self.push_front(data)
            return
        node = Node(data, self.tail, None)
        self.tail.next = node
        self.tail = node


    def push_values(self, data_list) :
        for data in data_list:
            self.push_back(data)

    def pop_front(self) :
        self.head = self.head.next
        self.head.prev = None
        if self.head is None :
            self.tail = None

    def pop_back(self) :
        self.tail = self.tail.prev
        self.tail.next = None
        if self.tail is None:
            self.head = None

    def assign_values(self, data_list) :
        self.head = None
        self.tail = None
        for data in data_list:
            self.push_back(data)
    
    def insert_at(self, index, data) :
        if index<0 or index>self.length():
            raise Exception("Invalid Index...")

        if index == 0 :
            self.push_front(data)
            return
        if index == self.length() :
            self.push_back(data)
            return
        itr = self.head
        count = 0
        while True:
            if count+1 == index :
                node = Node(data, itr, itr.next)
                itr.next.prev = node
                itr.next = node
                break
            if itr == self.tail:
                break
            count += 1
            itr = itr.next
        
    def remove_at(self, index) :
        if index<0 or index>=self.length():
            raise Exception("Invalid index...")

        if index == 0 :
            self.pop_front()
            return
        if index == (self.length()-1) :
            self.pop_back()
            return
        count = 0 
        itr = self.head
        while itr:
            if count == index :
                itr.prev.next = itr.next
                if itr.next:
                    itr.next.prev = itr.prev
            count += 1
            itr = itr.next
    
if __name__ == '__main__' :
    ll = doubleLinkedList()
    data_list = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j']
    ll.assign_values(data_list)
    ll.print()
    ll.push_values(['q','r','s','t','u','v','w','x','y','z'])
    ll.print()
    ll.remove_at(4)
    ll.print()
    ll.insert_at(4, '4')
    ll.print()
    ll.remove_at(0)
    ll.print()
    ll.insert_at(0, '0')
    ll.print()
    ll.pop_back()
    ll.print()
    ll.pop_front()
    ll.print()