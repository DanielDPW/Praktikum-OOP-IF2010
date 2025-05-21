import java.util.HashMap;

public class EnrollmentSystem {
    private HashMap<String, Student> students; // <studentID, Student>
    private HashMap<String, Course> courses; // <courseID, Course>

    // Ctor untuk membuat objek EnrollmentSystem
    // Inisialisasi students dan courses
    public EnrollmentSystem() {
        this.students = new HashMap<String, Student>();
        this.courses = new HashMap<String, Course>();
    }

    // Method untuk menambahkan student ke dalam sistem
    public void addStudent(String studentID, String name) {
        Student s = new Student(studentID, name);
        this.students.put(studentID, s);
    }

    // Method untuk menambahkan course ke dalam sistem
    public void addCourse(String courseID, String courseName) {
        Course c = new Course(courseID, courseName);
        this.courses.put(courseID, c);
    }

    // Method untuk mendaftar student ke dalam course
    // Jika student atau course tidak ditemukan, tampilkan pesan error
    // "Student atau course tidak ditemukan!" (tanpa tanda kutip)
    public void enrollStudentInCourse(String studentID, String courseID) {
        if (!students.containsKey(studentID)) {
            System.out.println("Student atau course tidak ditemukan!");
        } else {
            Student s = students.get(studentID);
            Course c = courses.get(courseID);
            s.enrollCourse(courseID);
            c.addStudent(studentID);
        }
    }

    // Method untuk menampilkan daftar course yang diambil oleh student
    // 
    // Student <studentName> terdaftar di <jumlah course> course:
    // <courseID1> <courseName1>
    // <courseID2> <courseName2>
    // ...
    //
    // Jika student tidak ditemukan, tampilkan pesan error
    // "Student tidak ditemukan!" (tanpa tanda kutip)
    public void displayCoursesForStudent(String studentID) {
        if (!students.containsKey(studentID)) {
            System.out.println("Student tidak ditemukan!");
        } else {
            Student s = students.get(studentID);
            System.out.println("Student " + s.getName() + " terdaftar di " + s.getEnrolledCourses().size() + " course:");
            for (String str : s.getEnrolledCourses()) {
                Course c = courses.get(str);
                System.out.println(c.getCourseID() + " " + c.getCourseName());
            }
        }
    }

    // Method untuk menampilkan daftar student yang terdaftar di course
    // 
    // Course <courseName> memiliki <jumlah student> student:
    // <studentID1> <studentName1>
    // <studentID2> <studentName2>
    // ...
    //
    // Jika course tidak ditemukan, tampilkan pesan error
    // "Course tidak ditemukan!" (tanpa tanda kutip)
    public void displayStudentsInCourse(String courseID) {
       if (!courses.containsKey(courseID)) {
            System.out.println("Course tidak ditemukan!");
        } else {
            Course c = courses.get(courseID);
            System.out.println("Course " + c.getCourseName() + " memiliki " + c.getEnrolledStudents().size() + " student:");
            for (String str : c.getEnrolledStudents()) {
                Student s = students.get(str);
                System.out.println(s.getStudentID() + " " + s.getName());
            }
        }
    }
}
