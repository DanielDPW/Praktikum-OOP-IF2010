public class LogMessageCommand implements Command {
    private final String message;

    public LogMessageCommand(String message) {
        this.message = message;
    }

    /**
     * Mencetak pesan:
     * "LOG: <message>"
     */
    @Override
    public void execute() {
        System.out.println("LOG: " + message);
    }

    @Override
    public String toString() {
        return "LogMessageCommand{" +
                "message='" + message + '\'' +
                '}';
    }
}