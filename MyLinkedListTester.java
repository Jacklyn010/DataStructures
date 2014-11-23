/*
 * NAME:  Kirk Srijongsirikul
 * ID:    A11687702
 * LOGIN: cs12eh0
 */
import junit.framework.*;
import java.util.LinkedList;
import java.util.ListIterator;
/**
 * Title: class MyLinkedListTester
 * Description: JUnit test class for MyLinkedList class
 * @author Kirk Srijongsirikul
 * @version 2.0 12-April-2014
 */

public class MyLinkedListTester extends TestCase
{
  private MyLinkedList<Integer> empty;
  private MyLinkedList<Integer> one;
  private MyLinkedList<Integer> several;
  private MyLinkedList<Integer> several2; // Tests clear for Integers
  private MyLinkedList<String> several3; // Tests clear for Strings
  private MyLinkedList<String> slist;
  private MyLinkedList<String> slist2; // Tests adding for Strings
  private MyLinkedList<String> slist3;
  static final int DIM = 5;
  static final int FIBMAX = 30;

  public MyLinkedListTester()
  {
    super();
  }

  /**
   * Standard Test Fixture. An empty list, a list with one entry (0) and
   * a list with several entries (0,1,2)
   */
  public void setUp()
  {
    empty = new MyLinkedList<Integer>();
    one = new MyLinkedList<Integer>();
    one.add(0, new Integer(0));
    //one.add(0, new Integer(5));
    several = new MyLinkedList<Integer>();
    several2 = new MyLinkedList<Integer>();
    // List: 1,2,3,...,Dim
    for(int i = DIM; i > 0; i--)
    {
      several.add(0, new Integer(i));
      several2.add(0, new Integer(i));
    }
    
    //List: "First", "Last"
    slist = new MyLinkedList<String>();
    slist.add(0, "First");
    slist.add(1, "Last");

    several3 = new MyLinkedList<String>();
    several3.add(0, "First");
    several3.add(1, "Middle");
    several3.add(2, "Last");

    slist2 = new MyLinkedList<String>();
    slist2.add(0,"Zero");
    slist2.add(1,"One");

    slist3 = new MyLinkedList<String>();
    slist3.add("Zero");
    slist3.add("One");
  }

  /** Test if heads of the lists are correct */
  public void testGetHead()
  {
    System.out.println("Testing Get Head");
    //for(int i = 0; i < several.size(); i++)
    {
      //System.out.println("Several@ i = " + several.get(i));
    }
    //for(int j = 0; j < one.size(); j++)
    {
      //System.out.println("One@ j = " + one.get(j));
    }
    assertEquals("Check 0 - One", new Integer(0), one.get(0));
    assertEquals("Check 0 - Several", new Integer(1), several.get(0));
  }

  /** Test if size of lists are correct */
  public void testListSize()
  {
    System.out.println("Testing Size");
    assertEquals("Check Empty Size",0,empty.size());
    assertEquals("Check One Size",1,one.size());
    assertEquals("Check Several Size",DIM,several.size());
  }

  /** Test setting a specific entry */
  public void testSet()
  {
    System.out.println("Testing Set");
    slist.set(1,"Final");
    assertEquals("Setting specific value", "Final", slist.get(1));
  }

  /** Test isEmpty */
  public void testEmpty()
  {
    System.out.println("Testing Empty");
    assertTrue("Empty is empty",empty.isEmpty());
    assertTrue("One is not empty",!one.isEmpty());
    assertTrue("Several is not empty",!several.isEmpty());
  }

  /** Test iterator on empty list and several list */
  public void testIterator()
  {
    System.out.println("Testing Iterator");
    int counter = 0;
    ListIterator<Integer> iter;
    for(iter = empty.listIterator(); iter.hasNext(); )
    {
      fail("Iterating empty list and found element");
    }
    counter = 0;
    for(iter = several.listIterator(); iter.hasNext(); iter.next())
      counter++;
    assertEquals("Iterator several count", counter, DIM);
  }

  /** Test out of bounds exception on get */
  public void testGetException()
  {
    System.out.println("Testing Get Out of Bounds Exception");
    try
    {
      empty.get(0);
      one.get(5);
      fail("Should have generated an exception");
    }
    catch(IndexOutOfBoundsException e)
    {
      // normal
    }
  }
public static int fib2(int num) {
        if (num <= 1) return num;
        return fib2(num - 2) + fib2(num - 1);
    }
  /** Test Iterator Fibonacci */
  public void testIteratorFibonacci()
  {
    System.out.println("Testing Iterator Fibonacci");
    MyLinkedList<Integer> fib = new MyLinkedList<Integer>();
    ListIterator<Integer> iter;
    // List: 0 1 1 2 3 5 8 13
    // Build the list with integers 1 .. FIBMAX
    int t, p = 0, q = 1;
    fib.add(0, p);
    fib.add(1, q);
    for(int k = 2; k < FIBMAX; k++)
    {
      t = p + q;
      fib.add(k,t);
      p = q; q = t;
    }
    
    for (int i = 0; i < fib.size(); i++) {
            System.out.println(i + ": " + fib.get(i) + " vs " + fib2(i));
        }
    // Now iterate through the list to near the middle, read the
    // previous two entries and verify the sum.
    iter = fib.listIterator();
    int sum = 0;
    for(int j = 1; j < FIBMAX/2; j++)
      sum = iter.next();
    System.out.println("We're at " + iter.previous());
    System.out.println("We should get " + sum);
    assertEquals("first", iter.previous() + iter.previous(), sum);
    // Go forward with the list iterator
    assertEquals("second", iter.next() + iter.next(), sum);
  }

  // 10 Made-Up Tests
  
  /** Test clear on Integers and Strings */
  public void testClear()
  {
    //System.out.println("----Original Tests----");
    System.out.println("Testing Clear -- Start of Original Tests--");
    several2.clear();
    several3.clear();
    assertTrue("Several2 has been cleared",several2.isEmpty());
    assertTrue("Several3 has been cleared",several3.isEmpty());
  }

  /** Test add an element at a specific index in the list*/
  public void testAddAtIndex()
  {
    System.out.println("Testing Adding at an Index");
    slist2.add(1,"CurrentOne");
    assertEquals("Checking adding at an index", "CurrentOne", slist2.get(1));
  }

  /** Test add an element at the end of the list */
  public void testAddAtEnd()
  {
    System.out.println("Testing Adding at the End");
    slist3.add("End");
    for(int i = 0; i < slist3.size(); i++)
    {
        System.out.println("SLIST3 = " + slist3.get(i));
    }
    System.out.println("Slist SIZE = " + slist3.size());
    assertEquals("Checking adding at the end", "End", 
        slist3.get(slist3.size() - 1));
  }
  
  /** Test removing an element */
  public void testRemove()
  {
    System.out.println("Testing Remove");
    slist2.remove(1);
    assertEquals("Checking removing an element at an index", 1, slist2.size());
  }

  /** Test index out of bounds exception on remove */
  public void testRemoveException()
  {
    System.out.println("Testing Remove Exception");
    try
    {
      slist2.remove(2);
      fail("Should have generated an exception");
    }
    catch(IndexOutOfBoundsException e)
    {
      // normal
    }
  }

  /** Test index out of bounds exception on add */
  public void testAddOutOfBoundsException()
  {
    System.out.println("Testing Add Out of Bounds Exception");
    try
    {
      slist.add(3, "Two");
      slist.add("Three");
      fail("Should have generated an exception");
    }
    catch(IndexOutOfBoundsException e)
    {
      // normal
    }
  }

  /** Test null pointer exception on add at index */
  public void testAddIndexNullPointerException()
  {
    System.out.println("Testing Add Null Pointer Exception");
    try
    {
      slist.add(0, null);
    }
    catch(NullPointerException e)
    {
      // normal
    }
  }

  /** Test null pointer exception on add at end */
  public void testAddEndNullPointerException()
  {
    try
    {
      slist.add(null);
      fail("Should have generated an exception.");
    }
    catch(NullPointerException e)
    {
      // normal
    }
  }

  /** Test index out of bounds exception on set */
  public void testSetException()
  {
    System.out.println("Testing Set Out of Bounds Exception");
    try
    {
      slist.set(2, "Two");
    }
    catch(IndexOutOfBoundsException e)
    {
      // normal
    }
  }
}
