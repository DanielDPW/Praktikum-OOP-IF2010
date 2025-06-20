import java.lang.reflect.Field;
import java.lang.reflect.Method;
import java.util.Scanner;

public class ReflectionCalculator {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);

        // Input case
        int tc = sc.nextInt();

        // Input 2 buah angka (a dan b)
        int a = sc.nextInt(), b = sc.nextInt();
        sc.close();

        // Reflection
        Calculator calc = new Calculator();
        Class<?> c = Class.forName("Calculator");

        switch (tc) {
            case 1:
                // a + b
                Method m = c.getDeclaredMethod("add", int.class, int.class);
                m.setAccessible(true);
                m.invoke(calc, a, b);
                break;
            case 2:
                // a - b
                Method n = c.getDeclaredMethod("subtract", int.class, int.class);
                n.setAccessible(true);
                n.invoke(calc, a, b);
                break;
            case 3:
                // a * b
                Method o = c.getDeclaredMethod("multiply", int.class, int.class);
                o.setAccessible(true);
                o.invoke(calc, a, b);
                break;
            case 4:
                // a / b dengan precision 2 (default)
                Method p = c.getDeclaredMethod("divide", int.class, int.class);
                p.setAccessible(true);
                p.invoke(calc, a, b);
                break;
            case 5:
                // a / b dengan precision 3
                Field f = c.getDeclaredField("precision");
                f.setAccessible(true);
                f.set(calc, 3);
                Method q = c.getDeclaredMethod("divide", int.class, int.class);
                q.setAccessible(true);
                q.invoke(calc, a, b);
                f.set(calc, 2);
                break;
            default:
                break;
        }
    }
}
