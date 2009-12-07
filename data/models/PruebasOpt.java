import java.util.Vector;

public class PruebasOpt
{
	private Vector<String> nombrePtos;
	private String M, fObj, bin="", enteros="", modelo="";
	private Vector<Integer> perm;
	
	PruebasOpt()
	{
		fObj="// Funcion Objetivo\n";
		fObj+="min:";
		modelo="// Calculo de las Distancias entre la escuela y las veredas\n";
		bin="// Restricciones Binarias\n";
		enteros="// Restricciones Binarias (2)\n";
		
		M="200";
		
		// Agregando los puntos de prueba
		nombrePtos = new Vector<String>();
		nombrePtos.addElement("10");
		nombrePtos.addElement("20");
		nombrePtos.addElement("25");
		//nombrePtos.addElement("40");
		
		perm = new Vector<Integer>();
		perm.addElement(0);
		perm.addElement(1);		
			
		modeloUnaDimension();
	}
	private void modeloUnaDimension()
	{
		calcularDistancias();
		modelo+="\n";
		calcularEnvidia();
		modelo=fObj+"\n"+modelo+"\n"+bin+"\n"+enteros;
		System.out.println (modelo);
	}	
	private void calcularDistancias()
	{
		for (int i = 0; i<nombrePtos.size(); i++) {
			String elm=nombrePtos.elementAt(i);
			modelo+="e - "+elm+" + "+M+" - "+M+" N"+i+" >= D"+i+";\n";
			modelo+="e - "+elm+" - "+M+" + "+M+" N"+i+" <= D"+i+";\n";
			modelo+="- e + "+elm+" + "+M+" N"+i+" >= D"+i+";\n";
			modelo+="- e + "+elm+" - "+M+" N"+i+" <= D"+i+";\n";
			
			bin+="N"+i+" <= 1;\n";
			
			if(i==0)
			{
				enteros+="int N0";
				fObj+=" D"+i;
			}
			else
			{
				enteros+=", N"+i;
				fObj+=" + D"+i;
			}
				
		}
	}
	private void sgtePermutacion()
	{
		int elm1 = perm.elementAt(0);
		int elm2 = perm.elementAt(1);
		int n = nombrePtos.size();
		
		if(elm2 == n-1)
		{
			elm1 ++;
			elm2 = elm1 + 1;
		}
		else
		{
			elm2++;
		}
		perm.setElementAt(elm1,0);
		perm.setElementAt(elm2,1);
	}
	private void calcularEnvidia()
	{
		int n = nombrePtos.size();
		int tam = (n-1)*n/2;
		
		for (int k = 0; k<tam; k++) 
		{
			int i = perm.elementAt(0);
			int j = perm.elementAt(1);
			modelo+="E"+i+""+j+" - D"+j+" + D"+i+" - "+M+" S"+i+""+j+" <= 0;\n";
			modelo+="E"+i+""+j+" - D"+i+" + D"+j+" - "+M+" S"+i+""+j+" >= -"+M+";\n";
			modelo+="E"+i+""+j+" - D"+i+" + D"+j+" + "+M+" S"+i+""+j+" <= "+M+";\n";
			modelo+="E"+i+""+j+" - "+M+" S"+i+""+j+" <= 0;\n";
			
			bin+="S"+i+""+j+" <= 1;\n";
			fObj+=" + E"+i+""+j;
			enteros+=", S"+i+""+j;

			sgtePermutacion();
		}
		
		fObj+=";\n";
		enteros+=";\n";
	}
	
	public static void main (String[] args) 
	{
		PruebasOpt obj=new PruebasOpt();
	}
}