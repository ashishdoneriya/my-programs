package manit;
import java.util.*;
class FindA_W
{
    public static void main(String args[])
	{
		Scanner in=new Scanner(System.in);
		int i,j,len;
		String name;
		char ch;
		while(true)
		{
			System.out.print("Enter your name : ");
			name=in.nextLine();
			len=name.length();
			if(len==0)
				System.exit(0);
			i=name.indexOf("a");
			j=name.indexOf("A");
			if (i==-1&&j==-1)
			{
				System.out.println("A is not found in "+name);
				System.exit(0);
			}
			int pos=(i!=-1?i:j);
			ch=name.charAt(pos);
			System.out.println("Position of "+ch+" in "+name+" is "+(pos+1));
			//System.out.println("Position of "+((i>j)?"a":"A")+" in "+name+" is "+((i!=-1?i:j)+1));
		}
	}
}