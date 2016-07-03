/**
 * 
 * @author Yasin Acikgoz
 *          2 polinomu birbiriyle toplayan, carpan, birbirinden cikaran,
 *          birbiriyle esitliklerini kontrol eden fonksiyonlari barindirir
 */
public class Polynomial {
    /**
     * Polinomun katsayilarini tutan katsayi arrrayi
     */
    public double coefficients[] = new double[10];
    /**
     * polinomun derecesini tutan integer degisken
     */
    public int degreeOfPoly;

    /**
     * @param a katsayilara initilize edilecek degerler
     * one parameter constructor
     */
    public Polynomial(double... a){
        int i = 0;
        double []temp=new double [10];
        for (double d : a) {
            setCoefficient(getCoefficients(), i, a[i]); //polinomun katsayi arrayini doldur
            ++i;
        }
        setDegreeOfPoly(i); //polinomun derecesini set et
    }
    /**
     * @return coefficients
     * getter for coefficient array
     */
    public double[] getCoefficients() { return coefficients; }
    /**
     * @return polinomun derecesi
     * getter for degree of polynomial
     */
    public int getDegreeOfPoly() { return degreeOfPoly; }
    /**
     * @param index coefficients arrayinin return edilecek elemaninin indexi
     * @return coefficients
     * getter for coefficent
     */
    public double getCoefficent(int index) { return coefficients[index]; }
    /**
     * @param coefficients set edilecek katsayi arrayi
     * @param index        katsayi arrayinin set edilecek indexi
     * @param elem         katsayi arrayine set edilecek deger
     * setter for coefficient
     */
    public void setCoefficient(double coefficients[], int index, double elem) {
        if(index>=0)
            coefficients[index] = elem;
    }
    /**
     * @param degree polinomun derecesi
     * setter for degree of polynomial
     */
    public void setDegreeOfPoly(int degree) {
        if(degree>=0)
            degreeOfPoly = degree;
    }

    /**
     * @param x polinomun sonucunu hesaplamak icin kullanilan deger
     * @return sonuc degeri
     * polinomun sonucunu hesaplayan method
     */
    public double evaluateThePoly(double x) {
        double result = 0;
        for (int i = 0; i < getDegreeOfPoly(); ++i)
            result += getCoefficent(i) * (Math.pow(x, i));
        return result;
    }
    /**
     * @param secondPoly toplama islemi yapilirken kullanilacak polinom objesi
     * @return toplama sonucu olusan polinom
     * 2 polinomu birbiriyle toplayan method
     */
    public Polynomial addPolys(Polynomial secondPoly) {
        int sizeMax;
        if(getDegreeOfPoly()>=secondPoly.getDegreeOfPoly())
            sizeMax = getDegreeOfPoly();
        else
            sizeMax = secondPoly.getDegreeOfPoly();
        
        //toplama islemi icin temp arrayler olustur
        double []sum1 = new double[sizeMax];
        double []sum2 = new double[sizeMax];
        
        Polynomial result = new Polynomial(0);
        result.setDegreeOfPoly(sizeMax);

        for (int i = sizeMax-1; i>=0; --i)
            sum1[i] = getCoefficent(i);
        for (int i = sizeMax-1; i>=0; --i)
            sum2[i] = secondPoly.getCoefficent(i);
        for(int i = sizeMax-1; i>=0; --i)
            result.setCoefficient(result.coefficients, i, sum1[i]+sum2[i]);
        return result;
    }
    /**
     * @param secondPoly cikarma islemi yapilirken kullanilacak polinom objesi
     * @return cikarma sonucu olusan polinom
     * 2 polinomu birbirinden cikartan method
     */
    public Polynomial substractPolys(Polynomial secondPoly) {
        int sizeMax;
        if(getDegreeOfPoly()>=secondPoly.getDegreeOfPoly())
            sizeMax = getDegreeOfPoly();
        else
            sizeMax = secondPoly.getDegreeOfPoly();
        
        //cikarma islemi icin temp arrayler olustur
        double []sum1 = new double[sizeMax];
        double []sum2 = new double[sizeMax];
        
        Polynomial result = new Polynomial(0);
        result.setDegreeOfPoly(sizeMax);

        for (int i = sizeMax-1; i>=0; --i)
            sum1[i] = getCoefficent(i);
        for (int i = sizeMax-1; i>=0; --i)
            sum2[i] = secondPoly.getCoefficent(i);
        for(int i = sizeMax-1; i>=0; --i)
            result.setCoefficient(result.coefficients, i, sum1[i]-sum2[i]);
        return result;
    }
    /**
     * @param secondPoly carpma islemi yapilirken kullanilacak polinom objesi
     * @return carpma sonucu olusan polinom
     * iki polinomu birbiriyle carpan method
     */
    public Polynomial multiplyPolys(Polynomial secondPoly) {
        Polynomial result = new Polynomial(0);
        int newDegreeOfPoly = getDegreeOfPoly() + secondPoly.getDegreeOfPoly()-1;
        result.setDegreeOfPoly(newDegreeOfPoly);
        
        double sum[] = new double[result.getDegreeOfPoly()+2];
        double res = 0.0;
        
        int sizeMax, sizeMin;

        if (getDegreeOfPoly() >= secondPoly.getDegreeOfPoly()) {
            sizeMax = getDegreeOfPoly();
            sizeMin = secondPoly.getDegreeOfPoly();
        } else {
            sizeMin = getDegreeOfPoly();
            sizeMax = secondPoly.getDegreeOfPoly();
        }
        for (int i = 0; i <=sizeMin; ++i) {
            for (int j = 0; j <=sizeMax; ++j) {
                res += getCoefficent(i) * secondPoly.getCoefficent(j);
                sum[i + j] += res;
                res = 0;
            }
        }
        for (int i = 0; i < newDegreeOfPoly; ++i)
            result.setCoefficient(result.getCoefficients(), i, sum[i]);
        return result;
    }
    /**
     * @return polinom stringi
     * override for toString
     */
    @Override
    public String toString() {
        String str = "";
        String sign;
        for (int i = getDegreeOfPoly()-1; i >=0;   --i) {
            if (getCoefficent(i) != 0) {
                if(getCoefficent(i)<0)
                    sign = " ";
                else
                    sign = " + ";
                if(i==getDegreeOfPoly()-1)
                    str = str + getCoefficent(i)+ "*x^"  + i;
                else if (i > 1)
                    str = str +  sign + getCoefficent(i)+ "*x^"  + i ;
                else if (i == 1)
                    str = str + sign+ getCoefficent(i) + "*x" ;
                else if(i==0)
                    str = str + sign+ getCoefficent(i);
            }
        }
        return str;
    }
    /**
     *
     * @param obj polinom objesi
     * @return iki polinom birbirine esitse true, aksi durumda false return eder.
     * override for equals
     */
    @Override
    public boolean equals(Object obj) {
        boolean status = false;
        if (!(obj instanceof Polynomial))
            return status;
        Polynomial secondPoly = (Polynomial)obj;
        if (getDegreeOfPoly() == secondPoly.getDegreeOfPoly()) {
            for (int i = 0; i < getDegreeOfPoly(); ++i) {
                if (getCoefficent(i) == secondPoly.getCoefficent(i))
                    status = true;
                else
                    return status;
            }
        }
        return status;
    }

    @Override
    public int hashCode() {
        int hash = 7;
        return hash;
    }
}