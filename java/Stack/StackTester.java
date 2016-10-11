class StackTester {
	public static void main(String[] args) {
		Stack<Integer> stack = new Stack<Integer>();
		
		for (int i = 5; i >= 0; i--) {
			stack.push(i);
			System.out.println("Pushed " + i);
		}
		
		System.out.println("Size: " + stack.size());
		System.out.println("Top: " + stack.peek());
		
		while (stack.size() > 0) {
			System.out.println(stack.pop());
		}
		
		System.out.println("Size: " + stack.size());
		System.out.print("Top: ");
		
		try {
			System.out.println(stack.peek());
		} catch (EmptyStackException e) {
			System.out.println(e.toString());
		}
		
		try {
			System.out.println(stack.pop());
		} catch (EmptyStackException e) {
			System.out.println(e.toString());
		}
	}
}
