import java.util.Vector;

public class Pruebas_2D
{
	private Vector<Punto> ptos;
	private String M, fObj, bin="", enteros="", modelo="";
	
	Pruebas_2D()
	{
		fObj="// Funcion Objetivo\n";
		fObj+="min:";
		modelo="// Calculo de las Distancias entre la escuela y las veredas\n";
		bin="// Restricciones Binarias\n";
		enteros="// Restricciones Binarias (2)\n";
		M="2000";
		
		// Agregando los puntos de prueba
		ptos = new Vector<Punto>();
		
		/// Prueba 1D
		/*ptos.addElement(new Punto(10.0,0.0));
		ptos.addElement(new Punto(15.0,0.0));
		ptos.addElement(new Punto(20.0,0.0));
		ptos.addElement(new Punto(25.0,0.0));
		ptos.addElement(new Punto(40.0,0.0));
		ptos.addElement(new Punto(50.0,0.0));
		ptos.addElement(new Punto(60.0,0.0));*/
		
		/// Prueba pdf
		ptos.addElement(new Punto(2.2,8.0));
		ptos.addElement(new Punto(3.6,1.7));
		ptos.addElement(new Punto(1.2,5.8));
		ptos.addElement(new Punto(5.5,7.0));
		ptos.addElement(new Punto(7.0,8.0));
		ptos.addElement(new Punto(9.8,5.7));
		ptos.addElement(new Punto(7.6,1.3));
		
				
		modelo="// Puntos\n// "+ptos.toString()+"\n\n"+modelo;
		modelo2D();
	}
	
	private void modelo2D()
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
		
		for (int i = 0; i<ptos.size(); i++) 
		{
			for (int j = 0; j<ptos.size(); j++) 
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
		for (int i = 0; i<ptos.size(); i++) 
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
		for (int i = 0; i<ptos.size(); i++) {
			double elmX=ptos.elementAt(i).getX();
			double elmY=ptos.elementAt(i).getY();
			
			modelo+="// Distancia de la escuela a "+i+"\n";
			modelo+="// Distancia en X\n";
			modelo+="Dx"+i+" - ex + "+elmX+" - "+M+" Nx"+i+" >= -"+M+";\n";
			modelo+="Dx"+i+" - ex + "+elmX+" + "+M+" Nx"+i+" <= "+M+";\n";
			modelo+="Dx"+i+" - "+elmX+" + ex + "+M+" Nx"+i+" >= 0;\n";
			modelo+="Dx"+i+" - "+elmX+" + ex - "+M+" Nx"+i+" <= 0;\n";
			modelo+="// Distancia en Y\n";
			modelo+="Dy"+i+" - ey + "+elmY+" - "+M+" Ny"+i+" >= -"+M+";\n";
			modelo+="Dy"+i+" - ey + "+elmY+" + "+M+" Ny"+i+" <= "+M+";\n";
			modelo+="Dy"+i+" - "+elmY+" + ey + "+M+" Ny"+i+" >= 0;\n";
			modelo+="Dy"+i+" - "+elmY+" + ey - "+M+" Ny"+i+" <= 0;\n";
			modelo+="// Distancia Total\n";
			modelo+="Dx"+i+" + Dy"+i+" = D"+i+";\n";
			
			bin+="Nx"+i+" <= 1;\n";
			bin+="Ny"+i+" <= 1;\n";
			if(i==0)
			{
				enteros+="int Nx0, Ny0";
				fObj+=" D"+i;
				//fObj+=" 0";
			}
			else
			{
				enteros+=", Nx"+i+", Ny"+i;
				fObj+=" + D"+i;
			}
				
		}
	}
	
	public static void main (String[] args) 
	{
		Pruebas_2D obj=new Pruebas_2D();
	}
}