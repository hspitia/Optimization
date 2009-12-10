import java.util.Scanner;
import java.util.HashMap;
import java.io.File;
import java.io.FileOutputStream;
import java.io.PrintStream;

public class Main
{
	public static void main (String[] args) throws Exception
	{
		//String input_name = "Tests/test_pdf.in";
//		String input_name = "Tests/2D_test.in";
		String input_name = args[0];
		
		// Data capture
		Scanner sc = new Scanner(new File(input_name));
		int region_size = sc.nextInt();
		int cities = sc.nextInt();
		String[] keys = new String[cities];
		Point[] values = new Point[cities];
		HashMap<String, Point> data = new HashMap<String, Point>();
		
		for (int i = 0; i<cities; i++) 
		{
			String name = sc.next();
			double x = Double.parseDouble(sc.next());
			double y = Double.parseDouble(sc.next());
			Point coords = new Point(x,y);
			
			// Data Store
			keys[i]=name;
			values[i]=coords;
			data.put(name,coords);
		}
		
		// Model Generation
		Test_2D obj = new Test_2D(region_size,cities,keys,values,data);
		String model=obj.solve();
		// File Output
		String file_name = input_name.substring(input_name.lastIndexOf("/"),input_name.indexOf("."));
		FileOutputStream outputFile = new FileOutputStream ("Outputs/"+file_name+".lp");
		PrintStream oStream = new PrintStream (outputFile);
		oStream.println (model);
		oStream.close();
		
	}
}