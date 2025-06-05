import java.lang.reflect.Field;
import java.lang.reflect.Method;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;

public class Reflection{
    //TIDAK BOLEH MENGUBAH NAMA METHOD YANG SUDAH ADA DAN PARAMS SERTA INPUT TYPENYA
    //BOLEH MENAMBAHKAN PRIVATE / PROTECTED METHOD SESUAI DENGAN KEBUTUHAN
    //DI LUAR SANA ADA KELAS YANG NAMANYA Ghost DAN Secret.

    public ArrayList<String> ghostMethods() {
        List<String> list = new ArrayList<String>();
        try {
            Class<?> c = Class.forName("Ghost");
            Method[] methods = c.getDeclaredMethods();

            for (Method m : methods) {
                list.add(m.getName());
            }
        } catch (Exception e) {
            e.getStackTrace();
        }
        return (ArrayList<String>)list;
    }   

    public Integer sumGhost() throws Exception {
        Integer sum = 0;
        Class<?> c = Class.forName("Ghost");
        Method[] methods = c.getDeclaredMethods();

        for (Method m : methods) {
            m.setAccessible(true);
            if (m.getReturnType() == Integer.class || m.getReturnType() == int.class) {
                Object instance = c.getDeclaredConstructor().newInstance();
                Object result = m.invoke(instance);
                if (result instanceof Integer) {
                    sum += (Integer) result;
                }
            }
        }
        return sum;
    }

    public String letterGhost() throws Exception {
        StringBuilder s = new StringBuilder();
        Class<?> c = Class.forName("Ghost");
        Method[] methods = c.getDeclaredMethods();

        for (Method m : methods) {
            m.setAccessible(true);
            if (m.getReturnType() == String.class) {
                Object instance = c.getDeclaredConstructor().newInstance();
                Object result = m.invoke(instance);
                if (result instanceof String) {
                    s.append((String) result);
                }
            }
        }
        return s.toString();
    }

    public String findSecretId(List<Secret> sl, String email) throws Exception {
        for (Secret s : sl) {
            if (s.isThis(email)) {
                Class<?> c = s.getClass();
                Field f = c.getDeclaredField("uniqueId");
                f.setAccessible(true);
                return (String) f.get(s);
            }
        }
        return "NaN";
    }
}