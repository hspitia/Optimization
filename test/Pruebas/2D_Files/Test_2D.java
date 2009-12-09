import java.util.Vector;
import java.util.HashMap;

public class Test_2D
{
	private Point[] points;
	private String obj, bin, ints, model, keys[];
	private int region_size, cities, M;
	private HashMap<String, Point> data;
	
	Test_2D(int region_size,int cities,String[] keys, Point[] values,HashMap<String, Point> data)
	{
		this.region_size=region_size;
		this.cities=cities;
		this.data=data;
		this.keys=keys;
		points=values;
		
		obj="// Funcion Objetivo\n";
		obj+="min:";
		model="// Calculo de las Distancias entre la escuela y las veredas\n";
		bin="// Restricciones Binarias\n";
		ints="// Restricciones Binarias (2)\n";
		M=2*region_size;
		model="// Points\n// "+printPoints()+"\n\n"+model;
	}
	public String solve()
	{
		model2D();
		return model;
	}
	private String printPoints()
	{
		String out="{"+points[0].toString();
		for (int i = 1; i<cities; i++)
		{
			out+=" , "+points[i].toString();
		}
		out+="}";
		return out;
	}
	private void model2D()
	{
		calculateDistances();
		model+="\n";
		calculateConditions();
		model=obj+"\n"+model+"\n"+bin+"\n"+ints;
	}
	private void calculateConditions()
	{
		model+="// Calculo de los condicionales de la vereda más lejana\n";
		String sumRi="";
		
		for (int i = 0; i<points.length; i++) 
		{
			for (int j = 0; j<points.length; j++) 
			{
				if(i!=j)
				{
					model+="D"+i+" - D"+j+" - "+M+" r"+i+" >= -"+M+";\n";
				}
			}
			if(i==0)
			{
				sumRi+="r"+i;
				
			}
			else
			{
				sumRi+=" + r"+i;
			}
			bin+="r"+i+" <= 1;\n";
			ints+=", r"+i;
		}
		sumRi+=" = 1;\n\n";
		model+="\n// Solo hay una mas lejana que las demas\n";
		model+=sumRi;
		ints+=";\n";
		
		model+="// Calculo de las distancias condicionadas\n";
		for (int i = 0; i<points.length; i++) 
		{
			model+="A"+i+" - D"+i+" - "+M+" r"+i+" >= -"+M+";\n";
			model+="A"+i+" - D"+i+" + "+M+" r"+i+" <= "+M+";\n";
			model+="A"+i+" - "+M+" r"+i+" <= 0;\n";
			obj+=" + A"+i;
		}
		
		obj+=";\n";
		
	}
	private void calculateDistances()
	{
		for (int i = 0; i<points.length; i++) {
			double elmX=points[i].getX();
			double elmY=points[i].getY();
			
			model+="// Distancia de la escuela a "+i+"\n";
			model+="// Distancia en X\n";
			model+="Dx"+i+" - ex + "+elmX+" - "+M+" Nx"+i+" >= -"+M+";\n";
			model+="Dx"+i+" - ex + "+elmX+" + "+M+" Nx"+i+" <= "+M+";\n";
			model+="Dx"+i+" - "+elmX+" + ex + "+M+" Nx"+i+" >= 0;\n";
			model+="Dx"+i+" - "+elmX+" + ex - "+M+" Nx"+i+" <= 0;\n";
			model+="// Distancia en Y\n";
			model+="Dy"+i+" - ey + "+elmY+" - "+M+" Ny"+i+" >= -"+M+";\n";
			model+="Dy"+i+" - ey + "+elmY+" + "+M+" Ny"+i+" <= "+M+";\n";
			model+="Dy"+i+" - "+elmY+" + ey + "+M+" Ny"+i+" >= 0;\n";
			model+="Dy"+i+" - "+elmY+" + ey - "+M+" Ny"+i+" <= 0;\n";
			model+="// Distancia Total\n";
			model+="Dx"+i+" + Dy"+i+" = D"+i+";\n\n";
			
			bin+="Nx"+i+" <= 1;\n";
			bin+="Ny"+i+" <= 1;\n";
			if(i==0)
			{
				ints+="int Nx0, Ny0";
				//obj+=" D"+i;
			}
			else
			{
				ints+=", Nx"+i+", Ny"+i;
				//obj+=" + D"+i;
			}
				
		}
	}
}