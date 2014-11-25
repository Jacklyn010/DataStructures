
/**
 * Write a description of class MyLinkedListDebugger here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
import java.util.ListIterator;
public class MyLinkedListDebugger {
    public static void test() {
        MyLinkedList<String> t = new MyLinkedList<String>();
        
        t.add(0, "hello");
        t.add(1, "world");
        t.set(1, "hax");
        t.add(2, "lol");
        t.add("lol");
        
        //t.remove(2);
        
        System.out.println("Size " + t.size());
        for (int i = 0; i < t.size(); i++) {
            System.out.println(i + ": " + t.get(i));
        }
        
        ListIterator<String> iter;
        for (iter = t.listIterator(); iter.hasNext();) {
            System.out.println(iter.next());
        }
        
        for (; iter.hasPrevious();) {
            System.out.println(iter.previous());
        }
    }
}
