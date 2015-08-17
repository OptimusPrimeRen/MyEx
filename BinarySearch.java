
class ab{

	public static void binary_search(int a[],int n,int start,int end){
		if (start >=end)
			System.out.println("not found");
		int middle = (start+end)/2;
		if(a[middle]>n)	binary_search(a,n,start,middle);
		else if(a[middle]<n) binary_search(a,n,middle,end);
		else System.out.println(middle);
	}

	public static void main(String args[]) {
		int[] a={0,3,5,6,8,10,14,15,18};
		binary_search(a,15,0,8);
  	}
  	
}