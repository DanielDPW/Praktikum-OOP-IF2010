/**
 * Exception yang dilempar ketika command tidak valid.
 * Menambahkan prefix "InvalidCommandException: " pada pesan error.
 */
public class InvalidCommandException extends Exception {
    public InvalidCommandException(String message) {
        super("InvalidCommandException: " + message);
    }
}