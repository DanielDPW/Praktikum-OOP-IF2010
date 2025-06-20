public class ShapeFactory {
    public Shape createShape(String shapeType) throws Exception {
        // Jika shapeType adalah null lempar exception dengan pesan "Shape type cannot be null"
        // Jika shapeType tidak sesuai dengan "CIRCLE", "RECTANGLE", atau "TRIANGLE" lempar exception dengan pesan "Unknown shape type: {shapeType}"
        
        // Sesuai dengan petunjuk, kita akan membuat factory method untuk membuat objek Shape berdasarkan tipe yang diberikan.
        if  (shapeType == null) {
            throw new RuntimeException("Shape type cannot be null");
        }

        if (!shapeType.equals("CIRCLE") && !shapeType.equals("RECTANGLE") && !shapeType.equals("TRIANGLE")) {
            throw new RuntimeException("Unknown shape type: " + shapeType);
        }

        if (shapeType == "CIRCLE") {
            return new Circle();
        } else if (shapeType == "RECTANGLE") {
            return new Rectangle();
        } else {
            return new Triangle();
        }
    }
}

