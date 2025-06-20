/**
 * Interface Command digunakan untuk menjalankan logika dari command.
 */
public interface Command {
    /**
     * Menjalankan logika dari command.
     */
    void execute();

    /**
     * Mengembalikan deskripsi dari command.
     */
    String toString();
}