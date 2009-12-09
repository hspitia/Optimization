import java.util.Vector;

public class Pruebas_1D
{
	private Vector<String> nombrePtos;
	private String M, fObj, bin="", enteros="", modelo="";
	private Vector<Integer> perm;
	
	Pruebas_1D()
	{
		fObj="// Funcion Objetivo\n";
		fObj+="min:";
		modelo="// Calculo de las Distancias entre la escuela y las veredas\n";
		bin="// Restricciones Binarias\n";
		enteros="// Restricciones Binarias (2)\n";
		M="2000";
		
		// Agregando los puntos de prueba
		nombrePtos = new Vector<String>();
		nombrePtos.addElement("10");
		nombrePtos.addElement("20");
		nombrePtos.addElement("25");
		nombrePtos.addElement("40");
		nombrePtos.addElement("50");
		nombrePtos.addElement("55");
		nombrePtos.addElement("60");
		
		perm = new Vector<Integer>();
		perm.addElement(0);
		perm.addElement(1);
		
		modelo="// Puntos\n// "+nombrePtos.toString()+"\n\n"+modelo;
		//modeloUnaDimension_modo1(); //Pedro
		//modeloUnaDimension_modo2(); //Incluyendo los ji tambien
		modeloUnaDimension_modo3(); // Modelo_Final
	}
	private void modeloUnaDimension_modo1()
	{
		calcularDistancias();
		modelo+="\n";
		calcularEnvidia_modo1();
		modelo=fObj+"\n"+modelo+"\n"+bin+"\n"+enteros;
		System.out.println (modelo);
	}	
	private void modeloUnaDimension_modo2()
	{
		calcularDistancias();
		modelo+="\n";
		calcularEnvidia_modo2();
		modelo=fObj+"\n"+modelo+"\n"+bin+"\n"+enteros;
		System.out.println (modelo);
	}
	private void modeloUnaDimension_modo3()
	{
		calcularDistancias();
		modelo+="\n";
		calcularCondicionalesYDistancias();
		modelo=fObj+"\n"+modelo+"\n"+bin+"\n"+enteros;
		System.out.println (modelo);
	}
	private void calcularCondicionalesYDistancias()
	{
		modelo+="// Calculo de los condicionales de la vereda más lejana\n";
		String sumatoriaRi="";
		
		for (int i = 0; i<nombrePtos.size(); i++) 
		{
			for (int j = 0; j<nombrePtos.size(); j++) 
			{
				if(i!=j)
				{
					modelo+="D"+i+" - D"+j+" - "+M+" r"+i+" >= -"+M+";\n";
				}
			}
			if(i==0)
			{
				sumatoriaRi+="r"+i;
				
			}
			else
			{
				sumatoriaRi+=" + r"+i;
			}
			bin+="r"+i+" <= 1;\n";
			enteros+=", r"+i;
		}
		sumatoriaRi+=" = 1;\n";
		modelo+=sumatoriaRi;
		enteros+=";\n";
		
		modelo+="// Calculo de las distancias condicionadas\n";
		
		for (int i = 0; i<nombrePtos.size(); i++) 
		{
			modelo+="A"+i+" - D"+i+" - "+M+" r"+i+" >= -"+M+";\n";
			modelo+="A"+i+" - D"+i+" + "+M+" r"+i+" <= "+M+";\n";
			modelo+="A"+i+" - "+M+" r"+i+" <= 0;\n";
			fObj+=" + A"+i;
		}
		
		fObj+=";\n";
		
	}
	private void calcularDistancias()
	{
		for (int i = 0; i<nombrePtos.size(); i++) {
			String elm=nombrePtos.elementAt(i);
			modelo+="// Distancia de la escuela a "+i+"\n";
			modelo+="e - "+elm+" + "+M+" - "+M+" N"+i+" >= D"+i+";\n";
			modelo+="e - "+elm+" - "+M+" + "+M+" N"+i+" <= D"+i+";\n";
			modelo+="- e + "+elm+" + "+M+" N"+i+" >= D"+i+";\n";
			modelo+="- e + "+elm+" - "+M+" N"+i+" <= D"+i+";\n";
			
			bin+="N"+i+" <= 1;\n";
			if(i==0)
			{
				enteros+="int N0";
				//fObj+=" D"+i;
				//fObj+=" 0";
			}
			else
			{
				enteros+=", N"+i;
				//fObj+=" + D"+i;
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
	private void calcularEnvidia_modo1()
	{
		int n = nombrePtos.size();
		int tam = (n-1)*n/2;
		
		for (int k = 0; k<tam; k++) 
		{
			int i = perm.elementAt(0);
			int j = perm.elementAt(1);
			modelo+="// Envidia de "+i+" con "+j+"\n";
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
	private void calcularEnvidia_modo2()
	{
		int n = nombrePtos.size();
		int tam = (n-1)*n/2;
		
		for (int k = 0; k<tam; k++) 
		{
			int i = perm.elementAt(0);
			int j = perm.elementAt(1);
			modelo+="// Envidia de "+i+" con "+j+"\n";
			modelo+="E"+i+""+j+" - D"+i+" + D"+j+" - "+M+" S"+i+""+j+" >= -"+M+";\n";
			modelo+="E"+i+""+j+" - D"+i+" + D"+j+" + "+M+" S"+i+""+j+" <= "+M+";\n";
			modelo+="E"+i+""+j+" - "+M+" S"+i+""+j+" <= 0;\n";
			
			modelo+="// Envidia de "+j+" con "+i+"\n";
			modelo+="E"+j+""+i+" - D"+j+" + D"+i+" - "+M+" S"+j+""+i+" >= -"+M+";\n";
			modelo+="E"+j+""+i+" - D"+j+" + D"+i+" + "+M+" S"+j+""+i+" <= "+M+";\n";
			modelo+="E"+j+""+i+" - "+M+" S"+j+""+i+" <= 0;\n";
			
			modelo+="// Envidias Asimetricas\n";
			modelo+="S"+i+""+j+" + S"+j+""+i+" = 1;";
			
			bin+="S"+i+""+j+" <= 1;\n";
			bin+="S"+j+""+i+" <= 1;\n";
			fObj+=" + E"+i+""+j+" + E"+j+""+i;
			enteros+=", S"+i+""+j+", S"+j+""+i;

			sgtePermutacion();
		}
		
		fObj+=";\n";
		enteros+=";\n";
	}
	
	public static void main (String[] args) 
	{
		Pruebas_1D obj=new Pruebas_1D();
	}
}