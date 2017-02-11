import javax.swing.JOptionPane;


public class problema4 {

	public static long mincm(long A, long B){
		long MCM = 0, mod = 0, MCD = 0, auxA = A, auxB = B;
	
	
			while(A%B!=0){
				mod = A%B;
				A=B;
				B=mod;
			};
			if (A%B==0)
				MCD = B;
		
		MCM = (auxA*auxB)/MCD;
		return MCM;
	}
	
	

	public static void main(String [] args){
	int cont = 0;
	long  n=0, a=0, b=0, t=0; 
	String values = "";
		
	//determinar el numero de casos
		do{
			try{
				n = Integer.parseInt(JOptionPane.showInputDialog("Ingresa cantidad de casos"));
			} catch (Exception ex) {
				JOptionPane.showMessageDialog(null, "Entrada Erronea!", "ERROR", JOptionPane.ERROR_MESSAGE);
			}
		}while(n<=0);
	
	

	
	
	


	
	for (int  i = 0; i<n; i++){
		do{
			try{
				values = JOptionPane.showInputDialog("Ingresa valores de a y b");
			} catch (Exception ex) {
				JOptionPane.showMessageDialog(null, "Entrada Erronea!", "ERROR", JOptionPane.ERROR_MESSAGE);
			}
		}while(values.length()<2);
		
		while(values.charAt(cont) != ' '){
			cont ++;
		}
		a = Long.parseLong(values.substring(0, cont));
		b = Long.parseLong(values.substring(cont +1));
		
		t = mincm(a, b);
		JOptionPane.showMessageDialog(null, t);
	}
	

	}
	
}
