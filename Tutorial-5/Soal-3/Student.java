import java.util.HashSet;

public class Student {
    private String studentID;
    private String name;
    private HashSet<String> enrolledCourses;

    // Ctor untuk membuat objek Student dengan ID dan nama
    // Note: jangan lupa untuk menginisialisasi enrolledCourses
    public Student(String studentID, String name) {
        this.studentID = studentID;
        this.name = name;
        this.enrolledCourses = new HashSet<String>();
    }

    // Method untuk menambahkan course ke dalam enrolledCourses
    public void enrollCourse(String courseID) {
        this.enrolledCourses.add(courseID);
    }

    // Getter untuk mendapatkan studentID
    public String getStudentID() {
        return this.studentID;
    }

    // Getter untuk mendapatkan name
    public String getName() {
        return this.name;
    }

    // Getter untuk mendapatkan daftar course yang diambil
    public HashSet<String> getEnrolledCourses() {
        return this.enrolledCourses;
    }
}
