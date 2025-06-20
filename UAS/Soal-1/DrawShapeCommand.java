public class DrawShapeCommand implements Command {
    private final String shape;

    public DrawShapeCommand(String shape) {
        this.shape = shape;
    }

    /**
     * Mencetak pesan:
     * "Menggambar <shape>"
     */
    @Override
    public void execute() {
        System.out.println("Menggambar " + shape);
    }

    @Override
    public String toString() {
        return "DrawShapeCommand{" +
                "shape='" + shape + '\'' +
                '}';
    }
}