/**
 * Based off of UCSD CSE 12, Assignment 2.
 */

import java.util.*;
public class MyLinkedList<E> extends AbstractList<E> {

    private int nelems;
    private Node head;
    private Node tail;

    protected class Node {
        E data;
        Node next;
        Node prev;

        /** Constructor to create singleton Node */
        public Node(E element)
        {
            this.data = element;
        }

        /** Constructor to create singleton link it between previous and next 
         *   @param element Element to add, can be null
         *   @param prevNode predecessor Node, can be null
         *   @param nextNode successor Node, can be null 
         */
        public Node(E element, Node prevNode, Node nextNode)
        {
            this.data = element;
            this.prev = prevNode;
            this.next = nextNode;
        }

        /** Remove this node from the link. Update previous and next nodes */
        public void remove()
        {
            this.next.setPrev(prev);
            this.prev.setNext(next);
        }

        /** Set the previous node in the list
         *  @param p new previous node
         */
        public void setPrev(Node p)
        {
            this.prev = p;
        }

        /** Set the next node in the list
         *  @param n new next node
         */
        public void setNext(Node n)
        {
            this.next = n;
        }

        /** Set the element 
         *  @param e new element 
         */
        public void setElement(E e)
        {
            this.data = e;
        }

        /** Accessor to get the next Node in the list */
        public Node getNext()
        {
            return this.next;
        }

        /** Accessor to get the prev Node in the list */
        public Node getPrev()
        {
            return this.prev;
        } 

        /** Accessor to get the Nodes Element */
        public E getElement()
        {
            return this.data;
        } 
    }

    /** ListIterator implementation */ 
    protected class MyListIterator implements ListIterator<E> {

        private boolean forward;
        private boolean canRemove;
        private Node left,right; // Cursor sits between these two nodes
        private int idx;        // Tracks current position. what next() would
        // return 
        public MyListIterator()
        {
            idx = 0;
            left = head;
            right = head.getNext();
        }

        @Override
        public void add(E e) throws  NullPointerException
        {
        }

        @Override
        public boolean hasNext()
        {
            return right != null && right.getElement() != null;
        }

        @Override
        public boolean hasPrevious()
        {
            return left != null && left.getElement() != null;
        }

        @Override
        public E next() throws NoSuchElementException
        {
            if (!hasNext()) throw new NoSuchElementException();
            
            E toReturn = right.getElement();
            idx = this.nextIndex();
            left = right;
            right = right.getNext();
            //E toReturn = right.getElement();
            
            return toReturn;
        }

        @Override
        public int nextIndex()
        {
            return idx + 1;
        }

        @Override
        public E previous() throws NoSuchElementException
        {
            if (!hasPrevious()) throw new NoSuchElementException();
            
            E toReturn = left.getElement();
            idx = this.previousIndex();
            left = left.getPrev();
            right = left;
            
            return toReturn;
        }

        @Override
        public int previousIndex()
        {
            return idx - 1;
        }

        @Override
        public void remove() throws IllegalStateException
        {
        }

        @Override
        public void set(E e) throws NullPointerException
        {
        }

    }

    //  Implementation of the MyLinkedList Class

    /** Only 0-argument constructor is define */
    public MyLinkedList() {
        clear();
    }

    @Override
    public int size() {
        return nelems;
    }

    @Override
    public E get(int index) throws IndexOutOfBoundsException {
        if (index >= this.size()) throw new IndexOutOfBoundsException();

        return this.getNth(index).getElement();
    }

    @Override
    /** Add an element to the list 
     * @param index  where in the list to add
     * @param data data to add
     * @throws IndexOutOfBoundsException
     * @throws NullPointerException
     */ 
    public void add(int index, E data) 
    throws IndexOutOfBoundsException,NullPointerException
    {
        if (data == null) throw new NullPointerException();
        if (index > this.size()) throw new IndexOutOfBoundsException();
        
        if (index == 0 && this.size() == 0) { // head add
            Node newNode = new Node(data, this.head, null);
            this.head.setNext(newNode);
            this.tail.setPrev(newNode);
            nelems++;
        } else if (index == this.size()) {
            add(data);
        } else {
            Node theNode = this.getNth(index);
        
            Node newNode = new Node(data, theNode.getPrev(), theNode);
            theNode.getPrev().setNext(newNode);
            theNode.setPrev(newNode);
            nelems++;
        }
    }

    /** Add an element to the end of the list 
     * @param data data to add
     * @throws NullPointerException
     */ 
    public boolean add(E data) throws NullPointerException
    {
        if (data == null) throw new NullPointerException();
        
        Node newNode = new Node(data, this.tail.getPrev(), this.tail);
        this.tail.getPrev().setNext(newNode);
        this.tail.setPrev(newNode);
        
        nelems++;
        
        return true;
    }

    /** Set the element at an index in the list 
     * @param index  where in the list to add
     * @param data data to add
     * @return element data added
     * @throws IndexOutOfBoundsException
     * @throws NullPointerException
     */ 
    public E set(int index, E data) 
    throws IndexOutOfBoundsException,NullPointerException
    {
        if (data == null) throw new NullPointerException();
        if (index >= this.size()) throw new IndexOutOfBoundsException();
        
        Node theNode = this.getNth(index);
        Node newNode = new Node(data, theNode.getPrev(), theNode.getNext());
        theNode.getPrev().setNext(newNode);
        theNode.getNext().setPrev(newNode);
        
        /*if (index == 0) {
            this.head.setNext(newNode);
        } else if (index == this.size() - 1) {
            this.tail.setPrev(newNode);
        }*/
        
        return theNode.data;
    }

    /** Remove the element at an index in the list 
     * @param index  where in the list to add
     * @return element the data found
     * @throws IndexOutOfBoundsException
     */ 
    public E remove(int index) throws IndexOutOfBoundsException
    {
        if (index >= this.size()) throw new IndexOutOfBoundsException();
        
        Node theNode = this.getNth(index);
        
        theNode.remove();
        
        nelems--;
        
        return theNode.data;
    }

    /** Clear the linked list */
    public void clear() {
        nelems = 0;
        this.head = new Node(null);
        this.tail = new Node(null, this.head, null);
        this.head.setNext(this.tail);
    }

    /** Determine if the list empty 
     *  @return true if empty, false otherwise */
    public boolean isEmpty()
    {
        return this.size() == 0;
    }

    public Iterator<E> QQQiterator()
    {
        return new MyListIterator();
    }

    public ListIterator<E> QQQlistIterator()
    {
        return new MyListIterator();
    }

    // Helper method to get the Node at the Nth index
    private Node getNth(int index) {
        if (index >= this.size()) return null;
        Node currentNode = this.head;
        for (int i = 0; i <= index; i++) {
            currentNode = currentNode.getNext();
        }
        return currentNode;
    }

                
    /*  UNCOMMENT the following when you believe your MyListIterator class is
    functioning correctly*/
    public Iterator<E> iterator()
    {
    return new MyListIterator();
    }
    public ListIterator<E> listIterator()
    {
    return new MyListIterator();
    }
     
}

// VIM: set the tabstop and shiftwidth to 4 
// vim:tw=78:ts=4:et:sw=4

