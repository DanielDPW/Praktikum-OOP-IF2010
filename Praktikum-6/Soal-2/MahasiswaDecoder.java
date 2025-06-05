import java.lang.reflect.*;

public class MahasiswaDecoder {
    private Mahasiswa mahasiswa;

    MahasiswaDecoder(Mahasiswa mahasiswa) {
        this.mahasiswa = mahasiswa;
    }

    public void addMatkul(String name) throws Exception {
        Class<?> c = Class.forName("Mahasiswa");
        Method m = c.getDeclaredMethod("addMatkul", String.class);
        m.setAccessible(true);
        m.invoke(mahasiswa, name);
    }



    public int getNIM() throws Exception {
        Class<?> c = Class.forName("Mahasiswa");
        Field f = c.getDeclaredField("NIM");
        f.setAccessible(true);
        return (int) f.get(mahasiswa);
    }

    public double getIPK() throws Exception {
        Class<?> c = Class.forName("Mahasiswa");
        Field f = c.getDeclaredField("IPK");
        f.setAccessible(true);
        return (double) f.get(mahasiswa);
    }

}
