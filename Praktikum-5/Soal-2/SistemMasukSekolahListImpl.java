import java.util.LinkedList;
import java.util.ArrayList;
import java.util.List;
import java.util.ListIterator;
import java.util.stream.Collectors;

/**
 * Implementasi dari interface SistemMasukSekolahList menggunakan LinkedList
 * PETUNJUK:
 * - Gunakan LinkedList sebagai struktur data utama
 * - Manfaatkan fitur Java Collections
 */
public class SistemMasukSekolahListImpl implements SistemMasukSekolahList {
    
    // Atribut: gunakan LinkedList<Student> untuk menyimpan data siswa
    private LinkedList<Student> students;
    
    /**
     * Constructor: inisialisasi LinkedList students
     */
    public SistemMasukSekolahListImpl() {
        this.students = new LinkedList<>();
    }
    
    @Override
    public void addStudent(Student student) {
        // TODO: Implementasikan method ini
        // Menambahkan siswa ke dalam list
        students.add(student);
    }
    
    @Override
    public void addFirstStudent(Student student) {
        // TODO: Implementasikan method ini
        // Menambahkan siswa di awal list
        students.addFirst(student);
    }
    
    @Override
    public void addLastStudent(Student student) {
        // TODO: Implementasikan method ini
        // Menambahkan siswa di akhir list
        students.addLast(student);
    }
    
    @Override
    public Student getFirstStudent() {
        // TODO: Implementasikan method ini
        // Mengambil siswa pertama di list
        return students.getFirst();
    }
    
    @Override
    public Student getLastStudent() {
        // TODO: Implementasikan method ini
        // Mengambil siswa terakhir di list
        return students.getLast();
    }
    
    @Override
    public Student removeFirstStudent() {
        // TODO: Implementasikan method ini
        // Menghapus dan mengembalikan siswa pertama di list
        return students.removeFirst();
    }
    
    @Override
    public Student removeLastStudent() {
        // TODO: Implementasikan method ini
        // Menghapus dan mengembalikan siswa terakhir di list
        return students.removeLast();
    }
    
    @Override
    public int removeStudentsByGpa(double minGpa) {
        // TODO: Implementasikan method ini
        // Menghapus siswa dengan GPA < minGpa
        // Return jumlah siswa yang dihapus
        
        int c = 0;
        ListIterator<Student> it = students.listIterator(0);
        
        while (it.hasNext()) {
            if (it.next().getGpa() < minGpa) {
                it.remove();
                c++;
            } 
        }

        return c;
    }
    
    @Override
    public List<Student> getStudentsWithHighGpa(double minGpa) {
        // TODO: Implementasikan method ini
        // Mencari siswa dengan GPA >= minGpa
        LinkedList<Student> l = new LinkedList<Student>();
        
        ListIterator<Student> it = students.listIterator(0);
        while (it.hasNext()) {
            Student s = it.next();
            if (s.getGpa() >= minGpa) {
                l.add(s);
            } 
        }
        return l;

    }
    
    @Override
    public List<Student> getStudentsByAge(int age) {
        // TODO: Implementasikan method ini
        // Mencari siswa dengan umur tertentu
        LinkedList<Student> l = new LinkedList<Student>();
        ListIterator<Student> it = students.listIterator(0);
        while (it.hasNext()) {
            Student s = it.next();
            if (s.getAge() == age) {
                l.add(s);
            } 
        }
        return l;
    }
    
    @Override
    public List<String> getYoungHighAchieverNames(int maxAge, double minGpa) {
        // TODO: Implementasikan method ini
        // Mencari nama siswa muda (umur < maxAge) dan berprestasi (GPA >= minGpa)
        LinkedList<String> l = new LinkedList<String>();
        ListIterator<Student> it = students.listIterator(0);
        while (it.hasNext()) {
            Student s = it.next();
            if (s.getGpa() >= minGpa && s.getAge() < maxAge) {
                l.add(s.getName());
            } 
        }
        return l;
    }
    
    @Override
    public List<Student> getAllStudents() {
        // TODO: Implementasikan method ini
        // Mengembalikan seluruh siswa dalam list
        LinkedList<Student> l = new LinkedList<Student>();
        ListIterator<Student> it = students.listIterator(0);
        while (it.hasNext()) {
            l.add(it.next());
            
        }
        return l;
    }
     
    
}

