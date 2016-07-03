/**
 * 
 * @author Yasin Acikgoz
 *          CSE 241 HW09 Fall 2015
 *      Main.java
 *      Created on 24.12.2015.
 */
public class Main {
    /**
     * 
     * @param args args
     */
    public static void main(String args[]) {
        
        Polynomial poly1 = new Polynomial(7,5.3,3,-1);
        Polynomial poly2 = new Polynomial(8,5);
        Polynomial poly3 = new Polynomial(1,6.4,6);
        Polynomial poly4 = new Polynomial(-9,7,12,0.34);
        Polynomial poly5 = new Polynomial(-1.5,9,12,0.66);
        Polynomial poly6 = new Polynomial(1,6.4,6);
        
        System.out.println("                 TESTER FOR HW09               ");
        System.out.println("___________________________________________\n\n");
        
        System.out.println("_____TEST FOR evaluateThePoly() METHOD____");
        System.out.printf("The result of '%s' polynomial for %f value is: %f\n", poly4, 6.5, poly4.evaluateThePoly(6.5));
        System.out.printf("\nThe result of '%s' polynomial for %f value is: %f\n", poly2, -3.0, poly2.evaluateThePoly(-3.0));
        System.out.printf("\nThe result of '%s' polynomial for %f value is: %f\n", poly1, 2.0, poly1.evaluateThePoly(2.0));
        
        System.out.println("\n\n_____TEST FOR addPolys() METHOD____");
        System.out.printf("( %s ) + ( %s ) = ( %s )\n", poly2, poly4, poly2.addPolys(poly4));
        System.out.printf("\n( %s ) + ( %s ) = ( %s )\n", poly1, poly3, poly1.addPolys(poly3));
        System.out.printf("\n( %s ) + ( %s ) = ( %s )\n", poly4, poly5, poly4.addPolys(poly5));
        
        System.out.println("\n\n_____TEST FOR substract() METHOD____");
        System.out.printf("( %s ) - ( %s ) = ( %s )\n", poly1, poly4, poly1.substractPolys(poly4));
        System.out.printf("\n( %s ) - ( %s ) = ( %s )\n", poly3, poly5, poly3.substractPolys(poly5));
        System.out.printf("\n( %s ) - ( %s ) = ( %s )\n", poly4, poly2, poly4.substractPolys(poly2));
        
        System.out.println("\n\n_____TEST FOR multiplyPolys() METHOD____");
        System.out.printf("( %s ) * ( %s ) = ( %s )\n", poly1, poly2, poly1.multiplyPolys(poly2));
        System.out.printf("\n( %s ) * ( %s ) = ( %s )\n", poly3, poly4, poly3.multiplyPolys(poly4));
        System.out.printf("\n( %s ) * ( %s ) = ( %s )\n", poly5, poly2, poly5.multiplyPolys(poly2));

        System.out.println("\n\n_____TEST FOR equals() OVERRIDE____");
        if(poly6.equals(poly3)){
            System.out.printf("( %s ) polynom is equal to ( %s ) polynom. \n", poly3, poly6);
        }
        if(!(poly1.equals(poly5))){
            System.out.printf("\n( %s ) polynom is NOT equal to ( %s ) polynom. \n", poly1, poly5);
        }
    }
}
